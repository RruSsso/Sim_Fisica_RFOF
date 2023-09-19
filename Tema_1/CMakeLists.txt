cmake_minimum_required(VERSION 3.26)
project(Tema_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tema_1 main.cpp)
find_package(box2d CONFIG REQUIRED)
target_link_libraries(Tema_1 PRIVATE box2d::box2d)