//
// Created by Federica Filippini on 16/11/2020.
//

#include "ScheduledJob.h"


void ScheduledJob::adjust_start_time() {

    if (start_time < job->get_submission_time())
        start_time = job->get_submission_time();

}



Job::time_instant ScheduledJob::get_end_time() const
{
    return start_time + job->get_execution_time();
}

Job::time_instant ScheduledJob::get_start_time() const
{
    return start_time;
}

Job::time_instant ScheduledJob::get_deadline() const
{
    return job->get_deadline();
}

Job::time_instant ScheduledJob::get_execution_time() const
{
    return job->get_execution_time();
}

Job::time_instant ScheduledJob::get_submission_time() const
{
    return job->get_submission_time();
}



void ScheduledJob::set_start_time(Job::time_instant st_time) {
    start_time = st_time;
    adjust_start_time(); // TO BE SAFE!!!
}

double ScheduledJob::evaluate() const {
    if (get_end_time() <= get_deadline())
        return 0.0;

    return job->get_weight() * (get_end_time() - get_deadline());
}



void ScheduledJob::print() const
{
    job->print();
    std::cout << " start_time " << start_time
              << " end_time " << get_end_time();
}
