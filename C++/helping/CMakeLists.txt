project(helping CXX)

cmake_minimum_required(VERSION 3.0)

file(GLOB SRC_HELPING *.cpp)

add_library(helping STATIC ${SRC_HELPING})