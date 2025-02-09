/*
 * Bisection.cpp
 *
 *  Created on: Oct 15, 2016
 *      Author: user
 */

#include "Bisection.hpp"

#include <iostream>
#include <cmath>
#include <cstdlib>

real Bisection::find_root(int &nit) const {

    nit = 1;

    real a = inf_limit;
    real b = sup_limit;
    real x0 = (a+b)/2;
    real f0 = func.eval(x0);

    bool conv = converged(b-a, f0);

    while(!conv and nit < max_iteration){

        if (func.eval(a) * f0 < 0)
            b = x0;
        else
            a = x0;

        x0 = (a+b)/2;
        f0 = func.eval(x0);

        conv = converged(b-a, f0);

        ++ nit;
    }

  return x0;
}
