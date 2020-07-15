cmake_minimum_required(VERSION 2.8.3)
project(algorithm)

#SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g")
add_compile_options(-std=c++11)
add_definitions(-std=c++11)



set(ALL_TARGET_LIBRARIES "")


include_directories(include ${catkin_INCLUDE_DIRS} ${PCL_INCLUDE_DIRS})
include_directories("${PROJECT_SOURCE_DIR}")

file(GLOB_RECURSE ALL_SRCS "*.cpp")

add_executable(main main.cpp ${ALL_SRCS})
target_link_libraries(main ${catkin_LIBRARIES} ${ALL_TARGET_LIBRARIES})