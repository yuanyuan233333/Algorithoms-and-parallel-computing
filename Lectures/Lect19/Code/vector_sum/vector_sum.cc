#include "vector_sum.hh"

namespace numeric
{
  std::vector<double>
  operator + (const std::vector<double> & x,
              const std::vector<double> & y)
  {
    std::vector<double> z (x.size ());

    for (std::vector<double>::size_type i = 0;
         i < x.size (); ++i)
      {
        z[i] = x[i] + y[i];
      }

    return z;
  }
}
