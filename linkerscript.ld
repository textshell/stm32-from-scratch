/* simple linker script for flash/sram embedded systems */

/* Written in 2015 by Martin Hostettler
 * To the extent possible under law, the author(s) have dedicated all copyright and related and neighboring rights to
 * this software to the public domain worldwide. This software is distributed without any warranty.
 * See <http://creativecommons.org/publicdomain/zero/1.0/> for detailed CC0 Public Domain Dedication.
 */
/* Copying and distribution of this file, with or without modification,
 * are permitted in any medium without royalty.  This file is offered as-is,
 * without any warranty. */

OUTPUT_FORMAT(elf32-littlearm)
OUTPUT_ARCH(arm)

LD_FEATURE ("SANE_EXPR")

MEMORY {
    FLASH : ORIGIN = 0x08000000, LENGTH = 64K
}

SECTIONS {
    .vectors : {
        KEEP(*(.vectors))
    } > FLASH

    .text : {
        *(.text*)
    } > FLASH
        
}


