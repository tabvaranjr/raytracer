cmake_minimum_required(VERSION 3.8)
project(raytracer-chapter2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(fmt CONFIG REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/lib)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE raytracer fmt::fmt fmt::fmt-header-only ${CMAKE_DL_LIBS})
