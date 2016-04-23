#pragma once

template <unsigned reg, unsigned bit>
constexpr __IO uint32_t& bit_band_alias_impl() {
    static_assert((0x40000000 <= reg && reg <= 0x400FFFFF)
                  || (0x20000000 <= reg && reg <= 0x200FFFFF), "reg outside bitbandable area");
    static_assert(bit <= 31, "bit must be <= 31");
    
    return reg >= 0x40000000 ? (*((uint32_t*)(0x42000000 + (reg - 0x40000000) * 32 + bit * 4)))
                             : (*((uint32_t*)(0x22000000 + (reg - 0x20000000) * 32 + bit * 4)));
}
static_assert((unsigned)&(bit_band_alias_impl<0x400FFFFF, 0>()) == 0x43FFFFE0, "bit_band_alias_impl is broken");
static_assert((unsigned)&(bit_band_alias_impl<0x200FFFFF, 0>()) == 0x23FFFFE0, "bit_band_alias_impl is broken");
#define bit_band_alias(reg, bit) bit_band_alias_impl<(unsigned)&(reg), bit>()

