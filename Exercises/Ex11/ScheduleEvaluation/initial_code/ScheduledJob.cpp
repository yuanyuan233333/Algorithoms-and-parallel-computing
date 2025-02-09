//
// Created by Federica Filippini on 16/11/2020.
//

#include "ScheduledJob.h"


/* YOUR CODE GOES HERE */



Job::time_instant ScheduledJob::get_end_time() const
{
    return start_time + /* YOUR CODE GOES HERE */get_execution_time();
}

Job::time_instant ScheduledJob::get_start_time() const
{
    return start_time;
}

Job::time_instant ScheduledJob::get_deadline() const
{
    return /* YOUR CODE GOES HERE */get_deadline();
}

Job::time_instant ScheduledJob::get_execution_time() const
{
    return /* YOUR CODE GOES HERE */get_execution_time();
}

Job::time_instant ScheduledJob::get_submission_time() const
{
    return /* YOUR CODE GOES HERE */get_submission_time();
}



/* YOUR CODE GOES HERE */



void ScheduledJob::print() const
{
    ptr->print();
    std::cout << " start_time " << start_time
              << " end_time " << get_end_time();
}
