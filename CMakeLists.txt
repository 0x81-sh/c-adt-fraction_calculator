cmake_minimum_required(VERSION 3.17)
project(fraction_calculator C)

set(CMAKE_C_STANDARD 99)

add_executable(fraction_calculator main.c fraction.h fraction.c)