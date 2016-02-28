#pragma once

#ifdef __cplusplus
extern "C" {
#else
#include "stdbool.h"
#endif

bool serial_writebyte_wait(unsigned char val);
void serial_writestr(const char* s);

#ifdef __cplusplus
}
#endif

