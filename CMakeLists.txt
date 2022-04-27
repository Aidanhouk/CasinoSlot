cmake_minimum_required(VERSION 3.1)

project(CasinoSlot)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/src")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.5.1/include")

link_directories("${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.5.1/lib")

file(GLOB_RECURSE SRC "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp")
add_executable("${PROJECT_NAME}" ${SRC})

# Link our executable to SFML and its dependencies
target_link_libraries("${PROJECT_NAME}" sfml-audio-d sfml-graphics-d sfml-window-d sfml-system-d)

# Set our source directory as the startup directory for debugging
set_target_properties("${PROJECT_NAME}" PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
