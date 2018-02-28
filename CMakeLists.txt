cmake_minimum_required(VERSION 3.9)
project(FdF)

set ( PROJECT_LINK_LIBS libft.a libmlx.a )

link_directories(libft minilibx)

include_directories(libft minilibx)

add_executable(FdF main.c)

target_link_libraries(FdF ${PROJECT_LINK_LIBS} )