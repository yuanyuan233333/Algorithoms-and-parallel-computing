//
// Created by Danilo Ardagna on 06/11/2020.
//

#include "Base.h"

int Base::f1() {
    return a++;
}

int Base::f2() {
    return b++;
}

void Base::print() const {
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
}


