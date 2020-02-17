cmake_minimum_required(VERSION 3.15)
project(341_project_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(341_project_1
        EntryList.cpp
        EntryList.h
        Graph.cpp
        Graph.h
        driver1.cpp)
