project(menu CXX)

cmake_minimum_required(VERSION 3.0)

file(GLOB SRC_MENU *.cpp)

add_library(menu STATIC ${SRC_MENU})