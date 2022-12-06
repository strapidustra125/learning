project(binaryTree CXX)

cmake_minimum_required(VERSION 3.0)

file(GLOB SRC_BINARYTREE *.cpp)

add_library(binaryTree STATIC ${SRC_BINARYTREE})