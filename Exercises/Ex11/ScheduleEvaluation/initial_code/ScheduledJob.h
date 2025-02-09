//
// Created by Federica Filippini on 16/11/2020.
//

#ifndef SCHEDULEEVALUATION_SCHEDULEDJOB_H
#define SCHEDULEEVALUATION_SCHEDULEDJOB_H

/* YOUR CODE GOES HERE */

#include "Job.h"

class ScheduledJob {

private:
    /* YOUR CODE GOES HERE */
    Job::time_instant start_time;

    void adjust_start_time();

public:
    ScheduledJob (/* YOUR CODE GOES HERE */, Job::time_instant st_time)
            : /* YOUR CODE GOES HERE */, start_time (st_time)
    {
        adjust_start_time();
    }

    ScheduledJob (Job j, Job::time_instant st_time)
            : /* YOUR CODE GOES HERE */
    {
        adjust_start_time();
    }

    explicit ScheduledJob (/* YOUR CODE GOES HERE */)
            : /* YOUR CODE GOES HERE */
    {}

    Job::time_instant get_end_time() const;
    Job::time_instant get_start_time() const;
    Job::time_instant get_deadline() const;
    Job::time_instant get_execution_time() const;
    Job::time_instant get_submission_time() const;

    void set_start_time (Job::time_instant  st_time);

    double evaluate() const;

    void print() const;
};


#endif //SCHEDULEEVALUATION_SCHEDULEDJOB_H
