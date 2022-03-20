cmake_minimum_required(VERSION 3.16)
project(sea_battle)

set(CMAKE_CXX_STANDARD 17)

set(MAIN_SOURCE main.cpp)
set(SOURCES ${MAIN_SOURCE} ship_factory.cpp)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

add_executable(${PROJECT_NAME} ${SOURCES})