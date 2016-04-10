#define STM32F103xB
#include <stm32f1xx.h>

#include "serial.h"

extern "C"
int main();

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

void Reset_Handler() {
    init_sram_sections();
    
    setup_serial(19200);
    serial_writestr("test\r\n");
    
    run_init_data();

    main();
}



