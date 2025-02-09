#include <iostream>

#include "C.h"
int main() {

    C c;
    const C const_c;

    c.f();
    const_c.f();

    return 0;
}