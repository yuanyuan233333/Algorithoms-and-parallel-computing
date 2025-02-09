#include <iostream>
#include "X.h"

int main() {
    X obj(3);
    std::cout << "Hello, World!" << std::endl;
    std::cout << obj.getMember() << std::endl;
    obj.setMember(10);
    std::cout << obj.getMember() << std::endl;
    return 0;
}
