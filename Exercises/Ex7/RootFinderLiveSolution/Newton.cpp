/*
 * Newton.cpp
 *
 *  Created on: Oct 15, 2016
 *      Author: user
 */

#include "Newton.hpp"

real Newton::find_root(int &nit) const {

  nit = 0;
  real x0 = x_init;
  real f0 = func.eval(x0);
  real der0 = der.eval(x0);

  bool conv = converged(f0/der0, f0);

  while (!conv and nit < max_iteration){

      x0 = x0 - f0/der0;
      f0 = func.eval(x0);
      der0 = der.eval(x0);

      conv = converged(f0/der0, f0);

      ++ nit;
  }

  return x0;
}
