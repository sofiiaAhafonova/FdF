cmake_minimum_required(VERSION 3.9)
project(FdF)

set ( PROJECT_LINK_LIBS libft.a libmlx_Linux.a )

link_directories(libft libmlx)

include_directories(libft libmlx)

add_executable(FdF main.c get_next_line.c get_next_line.h read_map.c fdf.h)

target_link_libraries(FdF ${PROJECT_LINK_LIBS} -Werror -Wextra -Wall -lmlx -lXext -lX11 )