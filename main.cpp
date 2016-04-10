#define STM32F103xB
#include <stm32f1xx.h>

#include "serial.h"

#include "test-language-features.h"

void init_sram_sections() {
    extern uint32_t __data_start_flash, __data_start_ram, __data_size;

    uint32_t *src = &__data_start_flash;
    uint32_t *dst = &__data_start_ram;
    uint32_t *dend = dst + ((uint32_t)&__data_size);

    while (dst < dend) {
        *dst++ = *src++;
    }

    extern uint32_t __bss_start, __bss_end;

    for (uint32_t* dst = &__bss_start; dst< &__bss_end; dst++) {
        *dst = 0;
    }
}

void run_init_data() {
    typedef void (*init_fun)(void);
    extern init_fun __init_array_start, __init_array_end;

    init_fun *ptr = &__init_array_start;
    while (ptr < &__init_array_end) {
        (*ptr)();
        ++ptr;
    }
}

// No atexit, no destructors

// actual signature is bool __aeabi_atexit(void* object, void (*destroyer)(void*), void* dso_handle)
extern "C" void __aeabi_atexit() {
}


/* needed for malloc in newlib */

extern "C" void* _sbrk(int increment);
void* __attribute__((weak)) _sbrk (int increment) {
    extern char __heap_start;
    extern char __heap_end;

    static void* __heap_top = &__heap_start;

    void *new_heap_top;
    if (__builtin_add_overflow((intptr_t)__heap_top, increment, (intptr_t*)&new_heap_top)) {
        return (void*)-1;
    }
    if (!(&__heap_start <= new_heap_top && new_heap_top <= &__heap_end)) {
        return (void*)-1;
    }

    void* old_top = __heap_top;
    __heap_top = new_heap_top;

    return old_top;
}



void mainFn() {

    init_sram_sections();

    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
    GPIOC->CRH = 0b0100'0100'0011'0100'0100'0100'0100'0100;
    GPIOC->BRR = 1 << 13;

    setup_serial(19200);
    serial_writestr("test\r\n");

    run_init_data();

    run_tests();
    run_tests_c();

    while (1) {
        int ctr;
        ctr = (8000000 / 3) / 2;
        // each loop iteration takes 3 cycles to execute.
        while (ctr) {
            asm ("");
            --ctr;
        }
        GPIOC->BRR = 1 << 13;
        ctr = (8000000 / 3) / 2;
        // each loop iteration takes 3 cycles to execute.
        while (ctr) {
            asm ("");
            --ctr;
        }
        GPIOC->BSRR = 1 << 13;
    }
}

extern char __stack_end;
extern void (* const vectors[])() __attribute__ ((section(".vectors"))) = {
                (void (*)())&__stack_end,
                mainFn,
};

