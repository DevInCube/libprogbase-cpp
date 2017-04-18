cmake_minimum_required(VERSION 2.8.7)

SET(CMAKE_CXX_FLAGS "-std=c++11 -Werror -Wall")

include_directories(include)
file(GLOB LIB_SOURCES "src/*.cpp")

project (progbase-cpp)
add_library(${CMAKE_PROJECT_NAME} STATIC ${LIB_SOURCES})
set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY C_STANDARD 99)
target_link_libraries(${CMAKE_PROJECT_NAME} progbase)

install(
    DIRECTORY include/ DESTINATION /usr/local/include
    FILES_MATCHING PATTERN "*.h"
)
install(TARGETS ${CMAKE_PROJECT_NAME} DESTINATION /usr/local/lib)


project (a.out)
add_executable(${CMAKE_PROJECT_NAME} "main.cpp")
set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY C_STANDARD 99)
target_link_libraries(${CMAKE_PROJECT_NAME} progbase progbase-cpp)
