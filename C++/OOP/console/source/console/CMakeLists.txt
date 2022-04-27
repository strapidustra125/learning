project(console CXX)

cmake_minimum_required(VERSION 3.0)

file(GLOB SRC_CONSOLE *.cpp)

add_library(console STATIC ${SRC_CONSOLE})