#define STM32F103xB
#include <stm32f1xx.h>

#include "serial.h"

extern "C"
int main();

void pll_start_hse() {

    // enable high speed external oscillator
    RCC->CR = (RCC->CR & ~RCC_CR_HSEBYP) | RCC_CR_HSEON;
    while (!(RCC->CR & RCC_CR_HSERDY)) {
        ;
    }

    // init pll
    int pllmul = 6;
    RCC->CFGR = (pllmul-2) << 18 | RCC_CFGR_PLLSRC | RCC_CFGR_PPRE1_DIV2;
    RCC->CR |= RCC_CR_PLLON;

    while (!(RCC->CR & RCC_CR_PLLRDY)) {
        ;
    }

    if (RCC->APB2ENR & RCC_APB2ENR_USART1EN) {
        // if usart1 is clocked wait to drain possible debugging infos.
        while ((USART1->SR & (USART_SR_TXE | USART_SR_TC)) != (USART_SR_TXE | USART_SR_TC)) {
            ;
        }
    }

    // switch sysclock to pll
    RCC->CFGR |= RCC_CFGR_SW_PLL;

    // wait for ack
    while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL) {
        ;
    }
}

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

    pll_start_hse();
    init_sram_sections();
    
    setup_serial(19200);
    serial_writestr("test\r\n");
    
    run_init_data();

    main();
}



