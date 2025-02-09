#include <iostream>
#include "MyFriendLibrary.h"

void bar(); // declaration

int main() {
    bar(); // here I would like to use my bar version
    bar(); // here I would like to use the library version
    return 0;
}

void bar(){ // definition
    std::cout << "Running main bar" << std::endl;
}