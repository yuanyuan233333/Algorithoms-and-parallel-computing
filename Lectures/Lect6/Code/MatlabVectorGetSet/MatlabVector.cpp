//
// Created by Danilo Ardagna on 09/06/2020.
//

#include "MatlabVector.h"

using std::cout;
using std::endl;

void MatlabVector::set(size_t n, double v)
{
    while (elem.size() < n+1)
        elem.push_back(0.);
    elem[n] = v;
}

double MatlabVector::get(size_t n)
{
    while (elem.size() < n+1)
        elem.push_back(0.);

    return elem[n];
}

void MatlabVector::print() const
{
    for (size_t i =0; i< elem.size(); ++i)
        cout << elem[i] << " ";

    cout << endl;
}

size_t MatlabVector::size() const
{
    return elem.size();
}

MatlabVector MatlabVector::operator*(double scalar) const
{
    MatlabVector result;
    for (unsigned i=0; i<elem.size(); ++i)
        result.set(i, scalar * elem[i]);

    return result;
}

MatlabVector operator+(MatlabVector& v1, MatlabVector& v2)
{
    MatlabVector result;
    for (unsigned i=0; i<v1.size(); ++i)
        result.set(i,v1.get(i) + v2.get(i));

    return result;
}



