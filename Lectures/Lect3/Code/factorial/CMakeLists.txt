cmake_minimum_required(VERSION 3.23)
project(factorial)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(factorial
        main.cpp)
