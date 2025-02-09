cmake_minimum_required(VERSION 3.16)
project(DocumentStore)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(DocumentStore
        Document.cpp
        Document.h
        DocumentStore.cpp
        DocumentStore.h
        main.cpp)
