#ifndef INTERPOLATION_HH
#define INTERPOLATION_HH

#include <vector>

#include "Point.h"

class Interpolation
{
   /* TO BE COMPLETED */
protected:
    std::vector<Point> points; // sorted_vector
    constexpr static double err_val = std::numeric_limits<double>::quiet_NaN();
public:
    explicit  Interpolation(const std::vector<Point> &);
    virtual double interpolate (double) const =0; /* TO BE COMPLETED */
    bool range_check (double) const;

    virtual ~Interpolation();
};

#endif // INTERPOLATION_HH
