cmake_minimum_required(VERSION 2.8)

project(extract)
include_directories("/usr/include/eigen3")

add_executable (extract extract.cpp)
