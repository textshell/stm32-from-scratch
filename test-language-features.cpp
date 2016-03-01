
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

class X {
public:
    X() {
        serial_writebyte_wait('X');
    }

    ~X() {
        serial_writebyte_wait('!');
    }
};

X x;

__attribute__((constructor (202)))
static void constructor2() {
        serial_writebyte_wait('2');
}

static void constructor1() __attribute__((constructor (200)));
static void constructor1() {
        serial_writebyte_wait('0');
}

void run_tests() {
    global_variable();
}
