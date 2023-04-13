cmake_minimum_required(VERSION 3.23)
project(Snake)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static")

set(SFML_STATIC_LIBRARIES TRUE)

set(SFML_DIR ${CMAKE_CURRENT_SOURCE_DIR}/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/SFML/include)

add_executable(Snake main.cpp Game.cpp Game.h)