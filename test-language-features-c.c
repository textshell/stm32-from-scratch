
#include "serial.h"

char test_common;


void run_tests_c(void) {
    if (test_common != 0) {
        serial_writebyte_wait('!');
    }
}
