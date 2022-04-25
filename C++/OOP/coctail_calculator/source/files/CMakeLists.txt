project(files CXX)

cmake_minimum_required(VERSION 3.0)

file(GLOB SRC_FILES *.cpp)

add_library(files STATIC ${SRC_FILES})