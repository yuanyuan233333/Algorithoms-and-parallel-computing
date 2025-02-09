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

  real a = inf_limit;
  real b = sup_limit;
  real u = func.eval(a);  // Eval f on boundary a
  real l = b - a;         // Interval length
  real r;                 // Residual
  real c = a + l * 0.5;     // Middle point

  nit = 0;
  r = func.eval(c);

  if (u * func.eval(b) >= 0.0) {
    std::cout << "Error Function has same sign at both endpoints" << std::endl;
    return -std::numeric_limits<real>::infinity();
  }

  while (!(converged(fabs(l), fabs(r))) && (nit <= max_iteration)) {
    (u * r < 0.) ? (b = c) : (a = c, u = r);
    l *= 0.5;
    c = a + l * 0.5;
    r = func.eval(c);
    ++nit;
  }
  return c;
}
