/*
 * RootFinder.cpp
 *
 *  Created on: Oct 15, 2016
 *      Author: user
 */

#include "RootFinder.hpp"

bool RootFinder::converged (real increment, real residual) const {
  /*
    Compares a parameter value against desired tolerance.
    The parameter is chosen upon the value of check.
  */

  if (increment < 0)
      increment *= -1;

  if (residual < 0)
      residual *= -1;

    switch (termination_criteria) {
        case INCREMENT:
            return increment < tolerance;

        case RESIDUAL:
            return residual < tolerance;

        case BOTH:
            return increment < tolerance and residual < tolerance;
    }
}
