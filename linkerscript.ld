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

    .rodata : {
        *(.rodata*)
    } > FLASH

    /* debug information, intentionally only support for modern dwarf */

    .debug_info 0 : { *(.debug_info*) }
    .debug_abbrev 0 : { *(.debug_abbrev*) }
    .debug_loc 0 : { *(.debug_loc*) }
    .debug_aranges 0 : { *(.debug_aranges*) }
    .debug_ranges 0 : { *(.debug_ranges*) }
    .debug_macro 0 : { *(.debug_macro*) }
    .debug_line 0 : { *(.debug_line*) }
    .debug_str 0 : { *(.debug_str*) }
    .debug_frame 0 : { *(.debug_frame*) }

    /DISCARD/ : {
        *(.note.GNU-stack)
        *(.gnu_debuglink)
        *(.gnu.lto_*)
        *(.comment)
        *(.ARM.attributes)
    }

    /* complain about contents in any sections we don't support or know about that linker or assembler generate */
    .unmatched : {
        KEEP("linker stubs"(*)) /* .glue_7 .glue_7t .vfp11_veneer .v4_bx */
        KEEP(*(.iplt))
        KEEP(*(.rel.iplt))
        KEEP(*(.igot.plt))
    } > FLASH
    ASSERT(SIZEOF(.unmatched) == 0, "allocated sections not matched. Search in linker map for .unmatched and add non empty sections explicitly in this file")
}


