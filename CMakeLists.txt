cmake_minimum_required(VERSION 3.23)
project(Snake)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static")
set(SFML_STATIC_LIBRARIES TRUE)

# You'd think this needs to go last but it needs to go first. The linking happens after the exe is built I guess
add_executable(Snake main.cpp Game.cpp Game.h)

# This section just finds SFML. We'll need to change this if we move SFML around. I'm doing it this way for portability
# I don't want the user to have to download a specfic SFML version if they want to see what I do.
set(SFML_DIR ${CMAKE_CURRENT_SOURCE_DIR}/SFML/lib/cmake/SFML)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/SFML/include)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

# Actually link the libraries. If you forget this, then the exe won't know what to do with the commands that we are given.
# Like sf::Texture won't have any constructor if nothing is linked to it.
target_link_libraries(Snake sfml-system sfml-window sfml-graphics sfml-audio)

