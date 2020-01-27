cmake_minimum_required(VERSION 3.8)
project(raytracer-dummy)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(raytracer-dummy main.cpp)
target_link_libraries(raytracer-dummy PRIVATE ${CMAKE_DL_LIBS})

