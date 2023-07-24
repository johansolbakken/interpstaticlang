cmake_minimum_required(VERSION 3.10)

project(islc)

set(CMAKE_CXX_STANDARD 23)

add_executable(islc src/islc.cpp)
target_include_directories(islc PRIVATE src)