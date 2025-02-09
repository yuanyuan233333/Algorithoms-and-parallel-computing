cmake_minimum_required(VERSION 3.20)
project(MatlabVectorGetSet)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(MatlabVectorGetSet
        main.cpp
        MatlabVector.cpp
        MatlabVector.h)
