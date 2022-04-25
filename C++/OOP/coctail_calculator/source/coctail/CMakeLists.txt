project(coctail_src CXX)

cmake_minimum_required(VERSION 3.0)

file(GLOB SRC_COCTAIL *.cpp)

add_library(coctail_src STATIC ${SRC_COCTAIL})