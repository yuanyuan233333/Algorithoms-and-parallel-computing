cmake_minimum_required(VERSION 3.16)
project(ScheduleEvaluation)

set(CMAKE_CXX_STANDARD 11)

add_executable(ScheduleEvaluation main.cpp Job.cpp Job.h ScheduledJob.cpp ScheduledJob.h Schedule.cpp Schedule.h)