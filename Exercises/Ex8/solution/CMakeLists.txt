cmake_minimum_required(VERSION 3.14)
project(Interpolation)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(Interpolation
        Interpolation.cpp
        Interpolation.h
        LinearInterpolation.cpp
        LinearInterpolation.h
        main.cpp
        NearestNeighborInterpolation.cpp
        NearestNeighborInterpolation.h
        Point.cpp
        Point.h
        StepwiseInterpolation.cpp
        StepwiseInterpolation.h)
