#include "Interpolation.h"

/* TO BE COMPLETED */
Interpolation::~Interpolation() {

}

bool Interpolation::range_check(double x) const {
    return (x < points.front().get_x()) or ( x >points.back() );
}

Interpolation::Interpolation (const std::vector<Point> & points)
        : points (points) {}