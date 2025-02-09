#include <iostream>

int main() {
    unsigned u = 10;
    int i = -42;
    long int l = -42;
    std::cout << i + i << std::endl;  // prints -84
    std::cout << u + i << std::endl;  // if 32-bit ints,
                                      // prints 4294967264
    std::cout << i + u << std::endl;  // if 32-bit ints,
                                      // prints 4294967264
    std::cout << u + l << std::endl; // prints -32

}
