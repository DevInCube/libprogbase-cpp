cmake_minimum_required(VERSION 2.8.7)

project (net)
add_executable(${CMAKE_PROJECT_NAME} "net.cpp")
target_link_libraries(${CMAKE_PROJECT_NAME} progbase-cpp progbase)

SET(CMAKE_CXX_FLAGS "-std=c++11 -Werror -Wall")
