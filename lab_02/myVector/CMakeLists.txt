cmake_minimum_required(VERSION 3.17)
project(myVector)

set(CMAKE_CXX_STANDARD 14)

include_directories(inc)

add_executable(myVector
        src/main.cpp
        src/myvector.cpp
        inc/myvector.hpp
        src/myiterator.cpp
        inc/myiterator.hpp
        )