#include <iostream>


// Which are the issues in the following code

int * f1(unsigned n);
int * f2(unsigned n);

int main() {

    int * p;
    for (unsigned i=1; i<5; ++i){
        p = f2(i);
        std::cout << *p << std::endl;
    }

    int *p3 =f1(4);

    std::cout << *p << std::endl;

    return 0;
}

int * f1(unsigned n){

    int *p1 = new int[n];

    return p1;
}

int * f2(unsigned n){
    int x = 5;

    int * p2 = f1(n);

    for (int i = 0; i< n ; ++i){
        std::cout << *p2 << " ";
        p2++;
    }


    std::cout << std::endl;

    std::cout << *p2 << std::endl;

    return &x;

}

