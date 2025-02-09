#include "LinearInterpolation.h"

/* TO BE COMPLETED */

LinearInterpolation::LinearInterpolation (const std::vector<Point> & points):
        Interpolation(points){}

double
LinearInterpolation::interpolate (double x) const
{
    std::vector<Point>::const_iterator previous = points.cbegin();
    std::vector<Point>::const_iterator previous2 = points.cbegin();
    std::vector<Point>::const_iterator current = ++previous2 ;
    // equivalent but less general.  OK for vectors or strings only
    // std::vector<Point>::const_iterator current = previous + 1  ;

    if (range_check(x)){
        // we are in range
        double result = 0;
        // find the sub interval where x lays
        while(current != points.cend() and current->get_x()< x){
            current++;
            previous++;
        }

        if (current != points.cend()){
            double x1 = previous->get_x();
            double x2 = current->get_x();
            double y1 = previous->get_y();
            double y2 = current->get_y();

            result = y1 + (y2 - y1) * (x - x1) / (x2 - x1);
        }

        return result;
        // perform computation



    }
    else
        return err_val;
}
