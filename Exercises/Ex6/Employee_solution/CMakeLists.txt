cmake_minimum_required(VERSION 3.16)
project(Employee)

set(CMAKE_CXX_STANDARD 14)

add_executable(Employee main.cpp Employee.cpp Employee.hpp Developer.cpp Developer.hpp Manager.cpp Manager.hpp Secretary.cpp Secretary.hpp
)
