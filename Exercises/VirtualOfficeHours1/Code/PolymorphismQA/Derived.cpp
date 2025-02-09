//
// Created by Danilo Ardagna on 06/11/2020.
//

#include "Derived.h"

int Derived::f1() {
    b = -100;
    c++;
    return -100;
}

int Derived::f2() {
    b = -100;
    c++;
    return -100;
}

void Derived::print() const{
    Base::print();
    std::cout << "c = " << c << std::endl;
}
