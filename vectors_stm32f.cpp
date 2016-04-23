
void Reset_Handler();

void Default_Handler();

extern "C"
void Default_HandlerWrapper() {
    Default_Handler();
}

#define DEFINE_HANDLER(name) void name ## _Handler(void) __attribute__ ((weak, alias("Default_HandlerWrapper")));

#define Irq0_Handler  WWDG_Handler
#define Irq1_Handler  PVD_Handler
#define Irq2_Handler  Tamper_Handler
#define Irq3_Handler  RTC_Handler
#define Irq4_Handler  FLASH_Handler
#define Irq5_Handler  RCC_Handler
#define Irq6_Handler  EXTI0_Handler
#define Irq7_Handler  EXTI1_Handler
#define Irq8_Handler  EXTI2_Handler
#define Irq9_Handler  EXTI3_Handler
#define Irq10_Handler EXTI4_Handler
#define Irq11_Handler DMA1_CH1_Handler
#define Irq12_Handler DMA1_CH2_Handler
#define Irq13_Handler DMA1_CH3_Handler
#define Irq14_Handler DMA1_CH4_Handler
#define Irq15_Handler DMA1_CH5_Handler
#define Irq16_Handler DMA1_CH6_Handler
#define Irq17_Handler DMA1_CH7_Handler
#define Irq18_Handler ADC1_2_Handler
#define Irq19_Handler USB_HP_CAN_TX_Handler
#define Irq20_Handler USB_HP_CAN_RX0_Handler
#define Irq21_Handler CAN_RX1_Handler
#define Irq22_Handler CAN_SCE_Handler
#define Irq23_Handler EXTI9_5_Handler
#define Irq24_Handler TIM1_BRK_Handler
#define Irq25_Handler TIM1_UP_Handler
#define Irq26_Handler TIM1_TRG_COM_Handler
#define Irq27_Handler TIM1_CC_Handler
#define Irq28_Handler TIM2_Handler
#define Irq29_Handler TIM3_Handler
#define Irq30_Handler TIM4_Handler
#define Irq31_Handler I2C1_EV_Handler
#define Irq32_Handler I2C1_ER_Handler
#define Irq33_Handler I2C2_EV_Handler
#define Irq34_Handler I2C2_ER_Handler
#define Irq35_Handler SPI1_Handler
#define Irq36_Handler SPI2_Handler
#define Irq37_Handler USART1_Handler
#define Irq38_Handler USART2_Handler
#define Irq39_Handler USART3_Handler
#define Irq40_Handler EXTI15_10_Handler
#define Irq41_Handler RTCAlarm_Handler
#define Irq42_Handler USBWakeup_Handler
#define Irq43_Handler TIM8_BRK_Handler
#define Irq44_Handler TIM8_UP_Handler
#define Irq45_Handler TIM8_TRG_COM_Handler
#define Irq46_Handler TIM8_CC_Handler
#define Irq47_Handler ADC3_Handler
#define Irq48_Handler FSMC_Handler
#define Irq49_Handler SDIO_Handler
#define Irq50_Handler TIM5_Handler
#define Irq51_Handler SPI3_Handler
#define Irq52_Handler UART4_Handler
#define Irq53_Handler UART5_Handler
#define Irq54_Handler TIM6_Handler
#define Irq55_Handler TIM7_Handler
#define Irq56_Handler DMA2_CH1_Handler
#define Irq57_Handler DMA2_CH2_Handler
#define Irq58_Handler DMA2_CH3_Handler
#define Irq59_Handler DMA2_CH45_Handler
// connectivity line only
#define Irq60_Handler DMA2_CH5_Handler
#define Irq61_Handler ETH_Handler
#define Irq62_Handler ETH_WKUP_Handler
#define Irq63_Handler CAN2_TX_Handler
#define Irq64_Handler CAN2_RX0_Handler
#define Irq65_Handler CAN2_RX1_Handler
#define Irq66_Handler CAN2_SCE_Handler
#define Irq67_Handler USB_FS_Handler

DEFINE_HANDLER(NMI)
DEFINE_HANDLER(HardFault)
DEFINE_HANDLER(MemManageFault)
DEFINE_HANDLER(BusFault)
DEFINE_HANDLER(UsageFault)
DEFINE_HANDLER(SVCall)
DEFINE_HANDLER(DebugMonitor)
DEFINE_HANDLER(PendSV)
DEFINE_HANDLER(Systick)
DEFINE_HANDLER(Irq0)
DEFINE_HANDLER(Irq1)
DEFINE_HANDLER(Irq2)
DEFINE_HANDLER(Irq3)
DEFINE_HANDLER(Irq4)
DEFINE_HANDLER(Irq5)
DEFINE_HANDLER(Irq6)
DEFINE_HANDLER(Irq7)
DEFINE_HANDLER(Irq8)
DEFINE_HANDLER(Irq9)
DEFINE_HANDLER(Irq10)
DEFINE_HANDLER(Irq11)
DEFINE_HANDLER(Irq12)
DEFINE_HANDLER(Irq13)
DEFINE_HANDLER(Irq14)
DEFINE_HANDLER(Irq15)
DEFINE_HANDLER(Irq16)
DEFINE_HANDLER(Irq17)
DEFINE_HANDLER(Irq18)
DEFINE_HANDLER(Irq19)
DEFINE_HANDLER(Irq20)
DEFINE_HANDLER(Irq21)
DEFINE_HANDLER(Irq22)
DEFINE_HANDLER(Irq23)
DEFINE_HANDLER(Irq24)
DEFINE_HANDLER(Irq25)
DEFINE_HANDLER(Irq26)
DEFINE_HANDLER(Irq27)
DEFINE_HANDLER(Irq28)
DEFINE_HANDLER(Irq29)
DEFINE_HANDLER(Irq30)
DEFINE_HANDLER(Irq31)
DEFINE_HANDLER(Irq32)
DEFINE_HANDLER(Irq33)
DEFINE_HANDLER(Irq34)
DEFINE_HANDLER(Irq35)
DEFINE_HANDLER(Irq36)
DEFINE_HANDLER(Irq37)
DEFINE_HANDLER(Irq38)
DEFINE_HANDLER(Irq39)
DEFINE_HANDLER(Irq40)
DEFINE_HANDLER(Irq41)
DEFINE_HANDLER(Irq42)
DEFINE_HANDLER(Irq43)
DEFINE_HANDLER(Irq44)
DEFINE_HANDLER(Irq45)
DEFINE_HANDLER(Irq46)
DEFINE_HANDLER(Irq47)
DEFINE_HANDLER(Irq48)
DEFINE_HANDLER(Irq49)
DEFINE_HANDLER(Irq50)
DEFINE_HANDLER(Irq51)
DEFINE_HANDLER(Irq52)
DEFINE_HANDLER(Irq53)
DEFINE_HANDLER(Irq54)
DEFINE_HANDLER(Irq55)
DEFINE_HANDLER(Irq56)
DEFINE_HANDLER(Irq57)
DEFINE_HANDLER(Irq58)
DEFINE_HANDLER(Irq59)
DEFINE_HANDLER(Irq60)
DEFINE_HANDLER(Irq61)
DEFINE_HANDLER(Irq62)
DEFINE_HANDLER(Irq63)
DEFINE_HANDLER(Irq64)
DEFINE_HANDLER(Irq65)
DEFINE_HANDLER(Irq66)
DEFINE_HANDLER(Irq67)


extern char __stack_end;
extern void (* const vectors[])() __attribute__ ((section(".vectors"))) = {
                (void (*)())&__stack_end,
                Reset_Handler,
                NMI_Handler,
                HardFault_Handler,
                MemManageFault_Handler,
                BusFault_Handler,
                UsageFault_Handler,
                0,
                0,
                0,
                0,
                SVCall_Handler,
                DebugMonitor_Handler,
                0,
                PendSV_Handler,
                Systick_Handler,
                Irq0_Handler,
                Irq1_Handler,
                Irq2_Handler,
                Irq3_Handler,
                Irq4_Handler,
                Irq5_Handler,
                Irq6_Handler,
                Irq7_Handler,
                Irq8_Handler,
                Irq9_Handler,
                Irq10_Handler,
                Irq11_Handler,
                Irq12_Handler,
                Irq13_Handler,
                Irq14_Handler,
                Irq15_Handler,
                Irq16_Handler,
                Irq17_Handler,
                Irq18_Handler,
                Irq19_Handler,
                Irq20_Handler,
                Irq21_Handler,
                Irq22_Handler,
                Irq23_Handler,
                Irq24_Handler,
                Irq25_Handler,
                Irq26_Handler,
                Irq27_Handler,
                Irq28_Handler,
                Irq29_Handler,
                Irq30_Handler,
                Irq31_Handler,
                Irq32_Handler,
                Irq33_Handler,
                Irq34_Handler,
                Irq35_Handler,
                Irq36_Handler,
                Irq37_Handler,
                Irq38_Handler,
                Irq39_Handler,
                Irq40_Handler,
                Irq41_Handler,
                Irq42_Handler,
                Irq43_Handler,
                Irq44_Handler,
                Irq45_Handler,
                Irq46_Handler,
                Irq47_Handler,
                Irq48_Handler,
                Irq49_Handler,
                Irq50_Handler,
                Irq51_Handler,
                Irq52_Handler,
                Irq53_Handler,
                Irq54_Handler,
                Irq55_Handler,
                Irq56_Handler,
                Irq57_Handler,
                Irq58_Handler,
                Irq59_Handler,
                Irq60_Handler,
                Irq61_Handler,
                Irq62_Handler,
                Irq63_Handler,
                Irq64_Handler,
                Irq65_Handler,
                Irq66_Handler,
                Irq67_Handler
};

