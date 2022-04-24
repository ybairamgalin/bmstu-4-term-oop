cmake_minimum_required(VERSION 3.17)
project(myVector)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS "-Werror")

include_directories(inc)
include_directories(src)

add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(myVectorGoogleTest
        tests/testmain.cpp
        src/myvector.hpp
        inc/myvector.h
        src/iterator.hpp
        inc/iterator.h
        inc/basecontainer.h
        inc/constiterator.h
        inc/myvectorexceptions.h
        src/constiterator.hpp)

target_link_libraries(
        myVectorGoogleTest
        gtest
        gtest_main
)
