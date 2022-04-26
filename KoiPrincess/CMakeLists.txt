cmake_minimum_required(VERSION 3.0.2)

project(CasinoSlot)

set(SFML_DIR "${CMAKE_SOURCE_DIR}/SFML-2.5.1/lib/cmake/SFML")

find_package(SFML 2.5.1 COMPONENTS audio graphics window system REQUIRED)

set(SOURCES
main.cpp
src/Constants.h
src/Application.h
src/Application.cpp
src/Button/Button.h
src/Button/Button.cpp
src/Config/Config.h
src/Config/Config.cpp
src/Field/Drum.h
src/Field/Drum.cpp
src/Field/Field.h
src/Field/Field.cpp
src/Field/Symbol/Symbol.h
src/Field/Symbol/Symbol.cpp
src/Field/Symbol/SymbolTexture.h
src/Field/Symbol/SymbolTexture.cpp
src/Field/Symbol/SymbolType.h
src/ResultController/ResultController.h
src/ResultController/ResultController.cpp
src/SpinController/SpinController.h
src/SpinController/SpinController.cpp
src/Sprite/Sprite.h
src/Sprite/Sprite.cpp
src/StateMachine/StateMachine.h
src/StateMachine/StateMachine.cpp
src/StateMachine/States/IState.h
src/StateMachine/States/IState.cpp
src/StateMachine/States/RunState.h
src/StateMachine/States/RunState.cpp
src/StateMachine/States/WaitState.h
src/StateMachine/States/WaitState.cpp
src/StateMachine/States/WinState.h
src/StateMachine/States/WinState.cpp
)

add_executable("${PROJECT_NAME}" ${SOURCES})

include_directories("${CMAKE_SOURCE_DIR}/src")

# Link our executable to SFML and its dependencies
target_link_libraries("${PROJECT_NAME}" sfml-audio sfml-graphics sfml-window sfml-system)

# Set our source directory as the startup directory for debugging
set_target_properties("${PROJECT_NAME}" PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

target_sources("${PROJECT_NAME}" PUBLIC main.cpp)
