cmake_minimum_required(VERSION 3.29)
project(DifferenceSchema)

set(CMAKE_CXX_STANDARD 20)

add_executable(DifferenceSchema main.cpp
        Calculate.cpp
        Calculate.h)
