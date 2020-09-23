cmake_minimum_required(VERSION 3.8)
project(raytracer)

#find_package(spdlog CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(raytracer Tuple.cpp Vector.cpp Point.cpp Math.cpp Math.h Color.cpp Color.h Canvas.cpp Canvas.h CanvasToPpm.cpp CanvasToPpm.h)
target_link_libraries(raytracer PRIVATE fmt::fmt fmt::fmt-header-only ${CMAKE_DL_LIBS})

