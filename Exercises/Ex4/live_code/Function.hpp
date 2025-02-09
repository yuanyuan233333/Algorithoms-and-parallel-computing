/*
 * Function.h
 *
 *  Created on: Oct 15, 2016
 *      Author: user
 */

#ifndef FUNCTION_H_
#define FUNCTION_H_

#include <iostream>
#include <vector>

//typedef double Point;
//typedef double Real;
//typedef std::vector<double> Coeff;

using Point = double;
using Real = double;
using Coeff = std::vector<double>;

class Function
{
private:
  std::vector<double> coefficients;

public:
  Function (const Coeff & coeff): coefficients (coeff) {};
  Real eval (Point x) const;
  Function derivative (void) const;
  void print (void) const;
};

#endif /* FUNCTION_H_ */
