
#include "serial.h"

static void constructor1(void) __attribute__((constructor (201)));
static void constructor1(void) {
        serial_writebyte_wait('1');
}


char test_common;

void run_tests_c(void) {
    if (test_common != 0) {
        serial_writebyte_wait('!');
    }
}
