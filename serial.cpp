#include "serial.h"

#define STM32F103xB
#include <stm32f1xx.h>

void setup_serial(int baud) {
    RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
    int divider = 48'000'000 / (16 * baud);

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
