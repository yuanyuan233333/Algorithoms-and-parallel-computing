#ifndef LINEAR_INTERPOLATION_HH
#define LINEAR_INTERPOLATION_HH

#include "Interpolation.h"

class LinearInterpolation: public Interpolation
{
public:
    // constructor
    explicit LinearInterpolation (const std::vector<Point> &);

    virtual double interpolate (double) const override;

    // destructor
    virtual ~LinearInterpolation (void) = default;
};

#endif // LINEAR_INTERPOLATION_HH
