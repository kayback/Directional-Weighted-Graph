cmake_minimum_required (VERSION 3.7)

project(graph)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")


add_executable(graph
                src/main.cpp
                src/graph.cpp
)

include_directories(
                src/
)
