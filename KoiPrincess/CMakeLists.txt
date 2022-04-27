cmake_minimum_required(VERSION 3.1)

project(CasinoSlot)

set(SFML_DIR "${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.5.1/lib/cmake/SFML")
set(SFML_DOC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.5.1/doc")

find_package(SFML 2.5.1 COMPONENTS audio graphics window system REQUIRED)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/src")

file(GLOB_RECURSE SRC "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp")

add_executable("${PROJECT_NAME}" ${SRC})

# Link our executable to SFML and its dependencies
target_link_libraries("${PROJECT_NAME}" sfml-audio sfml-graphics sfml-window sfml-system)

# Set our source directory as the startup directory for debugging
set_target_properties("${PROJECT_NAME}" PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

set_property(TARGET "${PROJECT_NAME}" PROPERTY CXX_STANDARD 14)
set_property(TARGET "${PROJECT_NAME}" PROPERTY CXX_STANDARD_REQUIRED ON)