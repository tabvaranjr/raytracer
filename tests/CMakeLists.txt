cmake_minimum_required(VERSION 3.8)
project(raytracer-tests)

find_package(Catch2 CONFIG REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(${CMAKE_SOURCE_DIR}/lib)

add_executable(raytracer-tests main.cpp tests-tuple.cpp tests-canvas.cpp tests-color.cpp)
target_link_libraries(raytracer-tests PRIVATE raytracer Catch2::Catch2 ${CMAKE_DL_LIBS})
