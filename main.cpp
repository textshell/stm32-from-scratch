#define STM32F103xB
#include <stm32f1xx.h>

#include "serial.h"
#include "bitband.h"

#include "test-language-features.h"

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

void Default_Handler() {
    while (true) {
        ;
    }
}

void TIM1_UP_Handler() {
    // Clear interrupts
    TIM1->SR = 0;
    bit_band_alias(GPIOC->ODR, 13) ^= 1;
}

void initTimer() {
    RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;

    RCC->APB2RSTR |= RCC_APB2RSTR_TIM1RST;
    RCC->APB2RSTR &= ~RCC_APB2RSTR_TIM1RST;

    TIM1->DIER = TIM_DIER_UIE;
    TIM1->CNT = 1;
    TIM1->ARR = 732 / 2;
    TIM1->PSC = 0xffff;
    TIM1->CR1 = TIM_CR1_CEN;

    // Clear interrupts
    TIM1->SR = 0;

    NVIC_EnableIRQ(TIM1_UP_IRQn);
    NVIC_SetPriority(TIM1_UP_IRQn, 15);
}

int main() {

    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
    GPIOC->CRH = 0b0100'0100'0011'0100'0100'0100'0100'0100;
    GPIOC->BRR = 1 << 13;



    run_tests();
    run_tests_c();


    if (1) {
        // use timer + interrupts for blinking
        initTimer();

        while (1) {
            __WFI();
        }

    } else {
        // use busy loop for blinking

        while (1) {
            int ctr;
            ctr = (48000000 / 3) / 2;
            // each loop iteration takes 3 cycles to execute.
            while (ctr) {
                asm ("");
                --ctr;
            }
            GPIOC->BRR = 1 << 13;
            ctr = (48000000 / 3) / 2;
            // each loop iteration takes 3 cycles to execute.
            while (ctr) {
                asm ("");
                --ctr;
            }
            GPIOC->BSRR = 1 << 13;
        }
    }

}

