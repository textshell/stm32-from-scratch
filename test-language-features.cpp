
#include "serial.h"

char test_global;

void global_variable() {
    if (test_global != 0) {
        serial_writebyte_wait('!');
    }
    test_global = 'a';
    serial_writebyte_wait(test_global);
    test_global = 'b';
    serial_writebyte_wait(test_global);
}

void run_tests() {
    global_variable();
}
