/*
 * Function.cpp
 *
 *  Created on: Oct 15, 2016
 *      Author: user
 */

#include <cmath>

#include "Function.hpp"

Real Function::eval (Point x) const
{
    Real evaluation = 0.0;

    for (std::size_t degree = 0; degree < coefficients.size(); ++degree)
        evaluation += coefficients[degree] * pow(x, degree);

    return evaluation;
}

Function Function::derivative() const
{
    Coeff dcoeffs;

    for (std::size_t degree = 1; degree < coefficients.size(); ++degree)
        dcoeffs.push_back(degree * coefficients[degree]);

    return Function(dcoeffs);
}

void Function::print() const
{
    for (std::size_t degree = coefficients.size() - 1; degree > 0; --degree)
        std::cout << coefficients[degree] << "*x^" << degree << " + ";

    std::cout << coefficients[0] << std::endl;
}
