//
// Created by Federica Filippini on 16/11/2020.
//

#include "Schedule.h"


/* YOUR CODE GOES HERE */


Schedule::size_type Schedule::size() const
{
    return order.size();
}


/* YOUR CODE GOES HERE */


void Schedule::print() const
{
    for (std::size_t i = 0; i < order.size(); ++i)
    {
        order[i].print();
        std::cout << std::endl;
    }
}
