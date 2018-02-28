cmake_minimum_required(VERSION 3.9)
project(FdF)

set(CMAKE_CXX_STANDARD 11)

find_library(FdF mlx)
add_executable(FdF
    README.md main.c)
