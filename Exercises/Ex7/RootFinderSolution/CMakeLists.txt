cmake_minimum_required(VERSION 3.15)
project(RootFinderSolution)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(RootFinderSolution
        Bisection.cpp
        Bisection.hpp
        Function.cpp
        Function.hpp
        Newton.cpp
        Newton.hpp
        Robust.cpp
        Robust.hpp
        RootFinder.cpp
        RootFinder.hpp
        rootfinding.hpp
        Roots2.cpp)
