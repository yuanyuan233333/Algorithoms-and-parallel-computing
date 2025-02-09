cmake_minimum_required(VERSION 3.20)
project(MatlabVectorReference)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(MatlabVectorReference
        main.cpp
        MatlabVector.cpp
        MatlabVector.h)
