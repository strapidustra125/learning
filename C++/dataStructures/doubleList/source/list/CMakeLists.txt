project(customStrings CXX)

cmake_minimum_required(VERSION 3.0)

file(GLOB SRC_CUSTOMSTRINGS *.cpp)

add_library(customStrings STATIC ${SRC_CUSTOMSTRINGS})