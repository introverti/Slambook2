#declare the mimimum version of cmake
cmake_minimum_required(VERSION 2.8)

#declare a cmake project
project (HelloSLAM)

#change mode
set( CMAKE_BUILD_TYPE "Debug")

#add a executable program
#program name + source code name
add_executable(helloSLAM helloSLAM.cpp)
add_library(hello libHelloSLAM.cpp)
add_library(hello_shared SHARED libHelloSLAM.cpp)

#link library to program
add_executable(useHello useHello.cpp)
target_link_libraries(useHello hello_shared)


