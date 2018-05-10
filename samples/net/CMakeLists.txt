cmake_minimum_required(VERSION 2.8.7)

set(CMAKE_FIND_LIBRARY_PREFIXES "lib")
set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
find_package(OpenSSL QUIET)

project (net)
add_executable(${CMAKE_PROJECT_NAME} "net.cpp")
target_link_libraries(${CMAKE_PROJECT_NAME} progbase-cpp progbase)
if (OPENSSL_FOUND) 
    target_link_libraries(${CMAKE_PROJECT_NAME} ssl)
endif()

project (https_client)
add_executable(${CMAKE_PROJECT_NAME} "https_client.cpp")
target_link_libraries(${CMAKE_PROJECT_NAME} progbase-cpp progbase)
if (OPENSSL_FOUND) 
    target_link_libraries(${CMAKE_PROJECT_NAME} ssl)
endif()

SET(CMAKE_CXX_FLAGS "-std=c++11 -Werror -Wall")
