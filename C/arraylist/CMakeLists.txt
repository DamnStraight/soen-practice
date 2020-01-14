cmake_minimum_required(VERSION 3.15)
project(arraylist C)

set(CMAKE_C_STANDARD 99)

add_executable(arraylist main.c arraylist.c arraylist.h)