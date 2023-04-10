cmake_minimum_required(VERSION 3.24)
project(pdb)

set(CMAKE_CXX_STANDARD 23)

add_library(pdb SHARED library.cpp)
