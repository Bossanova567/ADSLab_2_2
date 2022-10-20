cmake_minimum_required(VERSION 3.23)
project(ADSLab_2_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ADSLab_2_2
        Heap.cpp
        Heap.h
        main.cpp)
