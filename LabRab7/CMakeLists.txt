cmake_minimum_required(VERSION 3.17)
project(LabRab7)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)

add_subdirectory(src)
include_directories(src)

file(GLOB tests "test/*.cpp")

add_executable(LabRab7 ${tests})

target_link_libraries(LabRab7 src gtest gtest_main)