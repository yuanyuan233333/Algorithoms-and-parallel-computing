#include <iostream>

#include "Base.h"
#include "Derived.h"

void same(Base &b);

int main() {

    Base base1;
    Derived derived1;

    std::cout << "base1, derived1 output" << std::endl;

    std::cout << base1.f1() << std::endl;
    std::cout << base1.f2() << std::endl;

    base1.print();

    std::cout << derived1.f1() << std::endl;
    std::cout << derived1.f2() << std::endl;

    derived1.print();

    Base base2;
    Derived derived2;

    std::cout << "base2, derived2 output" << std::endl;

    same(base2);
    same(derived2);

}

void same(Base &b){

    std::cout << b.f1() << std::endl;
    std::cout << b.f2() << std::endl;
    b.print();
}