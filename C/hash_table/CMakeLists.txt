cmake_minimum_required(VERSION 3.15)
project(hash_table C)

set(CMAKE_C_STANDARD 99)

add_executable(hash_table main.c hash_table.c hash_table.h prime.c prime.h)