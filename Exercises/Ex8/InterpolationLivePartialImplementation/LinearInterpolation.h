#ifndef LINEAR_INTERPOLATION_HH
#define LINEAR_INTERPOLATION_HH

#include <vector>

#include "Interpolation.h"

/* TO BE COMPLETED */

class LinearInterpolation: public Interpolation
{

public:
  explicit LinearInterpolation (const std::vector<Point> &);

  virtual double interpolate (double) const override;
};

#endif // LINEAR_INTERPOLATION_HH
