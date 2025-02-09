cmake_minimum_required(VERSION 3.20)
project(LibrarySolution)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(LibrarySolution
        Book.cpp
        Book.h
        Library.cpp
        Library.h
        main.cpp)
