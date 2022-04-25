project(dataBase CXX)

cmake_minimum_required(VERSION 3.0)

file(GLOB SRC_DATABASE *.cpp)

add_library(dataBase STATIC ${SRC_DATABASE})