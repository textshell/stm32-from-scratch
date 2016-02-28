
#include "serial.h"

char test_global;

char test_init = 'c';

void global_variable() {
    if (test_global != 0) {
        serial_writebyte_wait('!');
    }
    test_global = 'a';
    serial_writebyte_wait(test_global);
    test_global = 'b';
    serial_writebyte_wait(test_global);

    serial_writebyte_wait(test_init);
    test_init = 'd';
    serial_writebyte_wait(test_init);
}

void run_tests() {
    global_variable();
}
