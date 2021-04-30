cmake_minimum_required (VERSION 2.8)
project(gaussNewton)
#添加C++11
set(CMAKE_CXX_FLAGS "-std=c++11")

find_package (OpenCV REQUIRED)
include_directories (${OpenCV_INCLUDE_DIRS})

#yaml-cpp
find_package(yaml-cpp REQUIRED)
include_directories(${YAML_CPP_INCLUDE_DIR})
include_directories ("/usr/include/eigen3")

add_executable(gaussNewton gaussNewton.cpp)
add_executable(useYaml useYaml.cpp)
add_executable (testYaml testYaml.cpp)
target_link_libraries(testYaml yaml-cpp)
target_link_libraries(useYaml yaml-cpp)
target_link_libraries(gaussNewton ${OpenCV_LIBS})

