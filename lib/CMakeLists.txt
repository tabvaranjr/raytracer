cmake_minimum_required(VERSION 3.8)
project(raytracer)

#find_package(spdlog CONFIG REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(raytracer Tuple.cpp)
target_link_libraries(raytracer PRIVATE ${CMAKE_DL_LIBS})

