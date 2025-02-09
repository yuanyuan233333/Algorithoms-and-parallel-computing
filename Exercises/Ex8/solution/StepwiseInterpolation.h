#ifndef STEPWISE_INTERPOLATION_HH
#define STEPWISE_INTERPOLATION_HH

#include "Interpolation.h"

class StepwiseInterpolation: public Interpolation
{
public:
    // constructor
    explicit StepwiseInterpolation (const std::vector<Point> &);

    virtual double interpolate (double) const override;

    // destructor
    virtual ~StepwiseInterpolation (void) = default;
};

#endif // STEPWISE_INTERPOLATION_HH
