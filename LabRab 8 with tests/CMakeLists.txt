cmake_minimum_required(VERSION 3.17)
project(LabRab8__1_)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)

add_subdirectory(src)
include_directories(src)

file(GLOB tests "test/*.cpp")

add_executable(LabRab8__1_ ${tests} test/tests.cpp)

target_link_libraries(LabRab8__1_ src gtest gtest_main)