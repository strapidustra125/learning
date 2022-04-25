project(ingredient CXX)

cmake_minimum_required(VERSION 3.0)

file(GLOB SRC_INGREDIENT *.cpp)

add_library(ingredient STATIC ${SRC_INGREDIENT})