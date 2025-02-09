#ifndef NEAREST_NEIGHBOR_INTERPOLATION_HH
#define NEAREST_NEIGHBOR_INTERPOLATION_HH

#include "Interpolation.h"

class NearestNeighborInterpolation: public Interpolation
{
public:
    // constructor
    explicit NearestNeighborInterpolation (const std::vector<Point> &);

    virtual double interpolate (double) const override;

    // destructor
    virtual ~NearestNeighborInterpolation (void) = default;
};

#endif // NEAREST_NEIGHBOR_INTERPOLATION_HH
