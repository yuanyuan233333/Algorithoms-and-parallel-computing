#include <iostream>

constexpr unsigned long fact (unsigned n){
    if (n==0)
        return 1;
    else
        return n*fact (n-1);
}

/* Iterative version also OK since C++ 14
constexpr unsigned long fact (unsigned n){
    unsigned long fact_value = 1;
    for (unsigned long i = 1; i <= n; ++i) {
        fact_value = fact_value * i;
    }
    return fact_value;
}
*/

int main() {
    constexpr unsigned long fact_3 = fact(3);
    int a[fact_3];
    std::cout << fact_3 << std::endl;
    return 0;
}

