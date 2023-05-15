cmake_minimum_required(VERSION 3.17)
project(inter)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-g)

add_executable(${PROJECT_NAME} Quicksort.cpp)
