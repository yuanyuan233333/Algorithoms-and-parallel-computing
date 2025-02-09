#ifndef INTERPOLATION_HH
#define INTERPOLATION_HH

#include <vector>

#include "Point.h"

class Interpolation
{
   /* TO BE COMPLETED */
protected:
  std::vector<Point> points; // sorted_vector

public:
  double interpolate (double) const; /* TO BE COMPLETED */
};

#endif // INTERPOLATION_HH
