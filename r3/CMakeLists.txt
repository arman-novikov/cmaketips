cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

set(PROJECT_NAME r3)

project(${PROJECT_NAME} LANGUAGES CXX)

add_library(message-obj OBJECT Message.hpp Message.cpp)

add_library(message-shared SHARED $<TARGET_OBJECTS:message-obj>)

add_library(message-static STATIC $<TARGET_OBJECTS:message-obj>)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} message-static)
