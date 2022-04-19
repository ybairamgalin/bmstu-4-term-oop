cmake_minimum_required(VERSION 3.17)
project(myVector)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(inc)
include_directories(src)

add_executable(myVector
        tests/testmain.cpp
        src/myvector.hpp
        inc/myvector.h
        src/iterator.hpp
        inc/iterator.h
        inc/basecontainer.h
)