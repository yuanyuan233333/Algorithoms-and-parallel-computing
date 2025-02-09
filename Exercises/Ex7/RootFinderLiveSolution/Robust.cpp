/*
 * Robust.cpp
 *
 *  Created on: Oct 15, 2016
 *      Author: user
 */

#include "Robust.hpp"

real Robust::find_root(int &nit_bis, int &nit_newt) const {

    Bisection bisection(func, inf_limit, sup_limit, tolerance * cratio,
                        termination_criteria, max_iteration);

    real x0_bis = bisection.find_root(nit_bis);

    Newton newton(func, x0_bis, tolerance, termination_criteria, max_iteration);

    //real x0_new = newton.find_root(nit_newt);

  return newton.find_root(nit_newt);
}

