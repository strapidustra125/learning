project(tests CXX)

cmake_minimum_required(VERSION 3.0)

file(GLOB SRC_TESTS ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp)
# file(GLOB SRC_TESTS ${CMAKE_CURRENT_SOURCE_DIR}/source/test_mbus.cpp)

add_library(tests STATIC ${SRC_TESTS})