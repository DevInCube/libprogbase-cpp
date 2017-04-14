cmake_minimum_required(VERSION 2.8.7)

project (a.out)
add_executable(${CMAKE_PROJECT_NAME} "net.cpp")
set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY C_STANDARD 99)
target_link_libraries(${CMAKE_PROJECT_NAME} progbase progbase-cpp)

SET(CMAKE_CXX_FLAGS "-std=c++11 -Werror -Wall")
