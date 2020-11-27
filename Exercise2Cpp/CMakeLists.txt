# cmake_minimum_required(VERSION <specify CMake version here>)
project(Exercise1Cpp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fopenmp")

add_executable(Exercise1Cpp main.cpp)