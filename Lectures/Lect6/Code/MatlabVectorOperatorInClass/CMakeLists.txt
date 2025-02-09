cmake_minimum_required(VERSION 3.20)
project(MatlabVectorOperatorInClass)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(MatlabVectorOperatorInClass
        main.cpp
        MatlabVector.cpp
        MatlabVector.h)
