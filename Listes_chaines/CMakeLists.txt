cmake_minimum_required(VERSION 3.15)
project(Listes_chaines C)

set(CMAKE_C_STANDARD 99)

add_library(Listes_chaines SHARED library.c library.h)