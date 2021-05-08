cmake_minimum_required (VERSION 2.8)
project(ch6)
#添加C++14
#使用最新的ceres库需要C++14 -o3
set(CMAKE_CXX_FLAGS "-std=c++14 -O3")
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

# Eigen
include_directories("/usr/include/eigen3")

#opencv
find_package (OpenCV REQUIRED)
include_directories (${OpenCV_INCLUDE_DIRS})

#yaml-cpp
find_package(yaml-cpp REQUIRED)
include_directories(${YAML_CPP_INCLUDE_DIR})
include_directories ("/usr/include/eigen3")

# Ceres
find_package(Ceres REQUIRED)
include_directories(${CERES_INCLUDE_DIRS})
# g2o
find_package(G2O REQUIRED)
include_directories(${G2O_INCLUDE_DIRS})

add_executable(gaussNewton gaussNewton.cpp)
add_executable(useYaml useYaml.cpp)
add_executable (testYaml testYaml.cpp)
add_executable(ceresCurveFitting ceresCurveFitting.cpp)
add_executable(g2oCurveFitting g2oCurveFitting.cpp)
target_link_libraries(g2oCurveFitting ${OpenCV_LIBS} ${G2O_CORE_LIBRARY} ${G2O_STUFF_LIBRARY})
target_link_libraries(ceresCurveFitting ${OpenCV_LIBS} ${CERES_LIBRARIES})
target_link_libraries(testYaml yaml-cpp)
target_link_libraries(useYaml yaml-cpp)
target_link_libraries(gaussNewton ${OpenCV_LIBS})

