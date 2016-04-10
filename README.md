Code for my blog series on bringing up an STM32F103C8T6 microcontroller.

Posts so far:

 * [STM32 from scratch, the bare minimum](http://tty.uchuujin.de/2016/02/stm32-from-scratch-bare-minimals/)
 * [STM32 from scratch, the hardware](http://tty.uchuujin.de/2016/02/stm32-from-scratch-the-hardware/)
 * [STM32 from scratch, serial](http://tty.uchuujin.de/2016/02/stm32-from-scratch-serial/)
 * [Makefile for embedded projects](http://tty.uchuujin.de/2016/02/stm32-from-scratch-makefile/)
 * [Enableing C/C++ features](http://tty.uchuujin.de/2016/03/stm32-from-scratch-enableing-c-c++-features/)
 * [Heap, malloc and new](http://tty.uchuujin.de/2016/04/stm32-from-scratch-heap/)

Toolchain tested with:

 * arm-none-eabi-gcc GNU Tools for ARM Embedded Processors) 5.2.1 20151202 (release) [ARM/embedded-5-branch revision 231848]
 * GNU ld (GNU Tools for ARM Embedded Processors) 2.25.90.20151217
 * [stm32flash](https://sourceforge.net/projects/stm32flash/)

But it should work with other toolchains versions too.

compile with:

```
make
```

flash with:
```
stm32flash -w out/main.bin /dev/ttyUSB1
```
