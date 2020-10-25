cmake_minimum_required(VERSION 3.17)
project(ls)

set(CMAKE_CXX_STANDARD 14)

add_executable(ls main.c flags.c)