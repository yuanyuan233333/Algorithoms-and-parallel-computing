cmake_minimum_required(VERSION 3.23)
project(returnThis)

set(CMAKE_CXX_STANDARD 11)

add_executable(returnThis main.cpp ReturnRef.cpp ReturnRef.h ReturnCopy.cpp ReturnCopy.h)
