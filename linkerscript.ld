OUTPUT_FORMAT(elf32-littlearm)
OUTPUT_ARCH(arm)

LD_FEATURE ("SANE_EXPR")

MEMORY {
    FLASH : ORIGIN = 0x08000000, LENGTH = 64K
}

SECTIONS {
    .vectors : {
        *(.vectors)
    } > FLASH

    .text : {
        *(.text*)
    } > FLASH
        
}


