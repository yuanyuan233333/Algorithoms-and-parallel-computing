#include <stdio.h>

int fib(int);

int main() {
    for (int i = 0; i<10; ++i)
        printf("Fib %d is %d\n", i, fib(i));
    return 0;
}


int fib(int n){
    int first = 0, second = 1;
    for (int i=0; i<n; ++i)  {
        int sum = first+second;
        first = second;
        second = sum;
    }
    return first;
}