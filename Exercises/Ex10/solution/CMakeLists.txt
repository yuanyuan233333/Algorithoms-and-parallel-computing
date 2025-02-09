cmake_minimum_required(VERSION 3.16)
project(Calendars)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(Calendars
        Calendar.cpp
        Calendar.h
        Event.cpp
        Event.h
        main.cpp)
