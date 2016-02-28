#define STM32F103xB
#include <stm32f1xx.h>


void mainFn() {
    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
    GPIOC->CRH = 0b0100'0100'0011'0100'0100'0100'0100'0100;
    GPIOC->BRR = 1 << 13;
        
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


extern void (* const vectors[])() __attribute__ ((section(".vectors"))) = {
                (void (*)())0x20000400,
                mainFn,
};

