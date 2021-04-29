cmake_minimum_required(VERSION 2.8)
project(useEigen)
include_directories("/usr/include/eigen3")
set ( CMAKE_BUILD_TYPE "Debug")
add_executable(useEigen eigenMatrix.cpp)

