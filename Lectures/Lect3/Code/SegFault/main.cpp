#include <iostream>


double* make(int n);
double* make_buggy();

int main()
{
    double *p = make(4);

    for (size_t i=0; i< 4; ++i)
        p[i] = i;

    for (size_t i=0; i< 4; ++i)
        std::cout << p[i] << " ";

    delete [] p;

    std::cout<<std::endl;

    p = make_buggy();

    for (size_t i=0; i< 4; ++i)
        p[i] = i;

    for (size_t i=0; i< 4; ++i)
        std::cout << p[i] << " ";

    delete [] p;
}


double* make(int n)	// allocate n doubles
{
    return new double[n];
}

double* make_buggy()
{
    double a[4];
    return a;

}