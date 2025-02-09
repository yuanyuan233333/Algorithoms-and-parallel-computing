cmake_minimum_required(VERSION 3.30)
project(KMeans_initial)

set(CMAKE_CXX_STANDARD 23)

add_executable(KMeans_initial KMeans.cpp Centroid.cpp Clustering.cpp Point.cpp)
