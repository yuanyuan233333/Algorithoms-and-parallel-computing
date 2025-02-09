//
// Created by Federica Filippini on 16/11/2020.
//

#include "Schedule.h"

void Schedule::validate()
{
    // guarantees that the schedule is valid,
    // i.e. a job starts after the end of the one before

    // an empty schedule is ok
    if (order.empty())
        return;

    order[0].set_start_time (order[0].get_submission_time());
    ScheduledJob pred = order[0];

    for (std::size_t i = 1; i < order.size(); ++i)
    {
        // adjust current job start time
        order[i].set_start_time (std::max (pred.get_end_time(),
                                           order[i].get_submission_time()));
        pred = order[i];
    }
}

Schedule::size_type Schedule::size() const
{
    return order.size();
}

double Schedule::evaluate() const
{
    double ret_val = 0;

    for (std::size_t i = 0; i < order.size(); ++i)
        ret_val += order[i].evaluate();

    return ret_val;
}

void Schedule::add (const std::shared_ptr<Job> & j)
{
    // this is the first job
    if (order.empty())
        order.push_back(ScheduledJob(j));
    else
    {
        ScheduledJob sj(j, order.back().get_end_time());
        order.push_back (sj);
    }
}

void Schedule::print() const
{
    for (std::size_t i = 0; i < order.size(); ++i)
    {
        order[i].print();
        std::cout << std::endl;
    }
}
