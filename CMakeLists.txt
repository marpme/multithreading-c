cmake_minimum_required(VERSION 3.6)
project(multithreading_c)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
    src/thread_bsp.c)

add_executable(multithreading_c ${SOURCE_FILES})