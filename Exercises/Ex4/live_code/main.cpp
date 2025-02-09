//============================================================================
// Name        : FunctionMin1.cpp
// Author      : Danilo
// Version     :
// Copyright   :
//============================================================================

#include <iostream>

#include "Function.hpp"
#include "FunctionMin.hpp"

using std::cout;
using std::endl;

int main()
{
  Function f ({1., 1., 2., -10., 2.});
  std::cout << "f(x) = ";
  f.print();
  std::cout << "f(1) = " << f.eval (1) << std::endl;

  Function der = f.derivative();
  std::cout << "f'(x) = ";
  der.print();

  FunctionMin minF (f, -1, 4, 1e-3, 1e-3, 1000000);
  std::cout << "Function minimum at: " << minF.solve() << std::endl;
  std::cout << "Function minimum (multi-start) at: "
            << minF.solve_multistart (100000) << std::endl;
  std::cout << "Function minimum (multi-start domain decomp) at: "
            << minF.solve_domain_decomposition (10, 100000) << std::endl;
  return 0;
}
