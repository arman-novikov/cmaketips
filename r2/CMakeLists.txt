cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

set(PROJECT_NAME r2)

project(${PROJECT_NAME} LANGUAGES CXX)

add_library(message STATIC Message.hpp Message.cpp)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} message)