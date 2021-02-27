cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME special)

project(${PROJECT_NAME} LANGUAGES CXX)

add_executable(${PROJECT_NAME} hello-world.cpp)