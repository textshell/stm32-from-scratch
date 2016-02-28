#define STM32F103xB
#include <stm32f1xx.h>

#include "serial.h"

#include "test-language-features.h"

void setup_serial(int baud) {
    RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
    int divider = 8000000 / (16 * baud);

    USART1->CR1 = USART_CR1_UE | USART_CR1_TE;
    USART1->CR2 = 0;
    USART1->CR3 = 0;
    USART1->BRR = divider << 4;

    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
    GPIOA->CRH |= GPIO_CRH_MODE9_1 | GPIO_CRH_CNF9_1;
    GPIOA->CRH &= ~(GPIO_CRH_CNF9_0 | GPIO_CRH_MODE9_0);
}

bool serial_writebyte_wait(unsigned char val) {
    while ((USART1->SR & USART_SR_TXE) == 0) ;
    USART1->DR = val;
    return 1;
}

void serial_writestr(const char* s) {
    for (const char*ch = s; *ch; ch++) {
        serial_writebyte_wait(*ch);
    }
}

void init_sram_sections() {

    extern uint32_t __bss_start, __bss_end;

    for (uint32_t* dst = &__bss_start; dst< &__bss_end; dst++) {
        *dst = 0;
    }
}

void mainFn() {

    init_sram_sections();

    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
    GPIOC->CRH = 0b0100'0100'0011'0100'0100'0100'0100'0100;
    GPIOC->BRR = 1 << 13;

    setup_serial(19200);
    serial_writestr("test\r\n");
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

