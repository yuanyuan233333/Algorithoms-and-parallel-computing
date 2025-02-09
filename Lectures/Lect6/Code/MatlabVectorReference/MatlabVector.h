//
// Created by Danilo Ardagna on 09/06/2020.
//

#ifndef MATLABVECTOR_MATLABLIKEVECTOR_H
#define MATLABVECTOR_MATLABLIKEVECTOR_H

#include <vector>
#include <iostream>

class MatlabVector {

    std::vector<double> elem;

public:

    double & operator[](size_t n);
    size_t size() const; // return number of elements

    void print() const;

    MatlabVector operator*(double scalar) const;
};

MatlabVector operator+(MatlabVector& v1, MatlabVector& v2);

#endif //MATLABVECTOR_MATLABLIKEVECTOR_H
