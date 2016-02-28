Code for my blog series on bringing up an STM32F103C8T6 microcontroller.

Posts so far:

 * [STM32 from scratch, the bare minimum](http://tty.uchuujin.de/2016/02/stm32-from-scratch-bare-minimals/)
 * [STM32 from scratch, the hardware](http://tty.uchuujin.de/2016/02/stm32-from-scratch-the-hardware/)
 * [STM32 from scratch, serial](http://tty.uchuujin.de/2016/02/stm32-from-scratch-serial/)

Toolchain tested with:

 * arm-none-eabi-gcc GNU Tools for ARM Embedded Processors) 5.2.1 20151202 (release) [ARM/embedded-5-branch revision 231848]
 * GNU ld (GNU Tools for ARM Embedded Processors) 2.25.90.20151217
 * [stm32flash](https://sourceforge.net/projects/stm32flash/)

But it should work with other toolchains versions too.

compile with:

```
arm-none-eabi-g++ -c -mcpu=cortex-m3 -mthumb --std=c++14 -O2 -fno-rtti -fno-exceptions -I common/stm_include -I common/cmsis_include main.cpp -o main.o
arm-none-eabi-g++ -mcpu=cortex-m3 -mthumb -Tlinkerscript.ld -nostartfiles main.o -o main.elf
arm-none-eabi-objcopy -O binary main.elf main.bin
```

flash with:
```
stm32flash -w main.bin /dev/ttyUSB1
```
