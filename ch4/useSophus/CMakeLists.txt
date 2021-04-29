cmake_minimum_required(VERSION 2.8)

project(useSophus)
find_package (Sophus REQUIRED)
include_directories("/usr/include/eigen3")
include_directories(${Sophus_INCLUDE_DIRS})
add_executable (useSophus useSophus.cpp)
#新版本的Sophus不需要链接外部库
target_link_libraries(useSophus Sophus::Sophus)
