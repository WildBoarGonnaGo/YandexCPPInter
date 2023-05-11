cmake_minimum_required(VERSION 3.17)
project(inter)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-g)

add_executable(${PROJECT_NAME} TwoSum.cpp)
# target_include_directories(${PROJECT_NAME} PUBLIC /opt/homebrew/include)
# target_link_directories(${PROJECT_NAME} PUBLIC /opt/homebrew/Cellar/boost/1.81.0_1/lib)
# target_link_libraries(${PROJECT_NAME} PUBLIC -lboost_iostreams -lboost_system -lboost_filesystem)
