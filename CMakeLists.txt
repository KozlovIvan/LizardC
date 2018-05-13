cmake_minimum_required(VERSION 3.8)
project(Lizard)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c lizard.h)
add_executable(Lizard ${SOURCE_FILES})