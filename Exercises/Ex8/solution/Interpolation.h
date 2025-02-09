#ifndef INTERPOLATION_HH
#define INTERPOLATION_HH

#include <vector>
#include <limits>

#include "Point.h"

class Interpolation
{
protected:
    std::vector<Point> points; // sorted_vector
    constexpr static double err_val = std::numeric_limits<double>::quiet_NaN();

public:
    // constructor
    explicit Interpolation (const std::vector<Point> &);

    virtual double interpolate (double) const = 0;
    bool range_check (double) const;

    // destructor
    virtual ~Interpolation (void) = default;
};

#endif // INTERPOLATION_HH
