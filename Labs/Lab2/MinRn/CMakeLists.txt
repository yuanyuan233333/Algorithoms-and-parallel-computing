cmake_minimum_required(VERSION 3.16)
project(MinRn)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(MinRn
        FunctionMin3.cpp
        FunctionMinRn.cpp
        FunctionMinRn.h
        FunctionRn.cpp
        FunctionRn.h
        Monomial.cpp
        Monomial.h
        Point.cpp
        Point.h)
