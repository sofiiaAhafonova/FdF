cmake_minimum_required(VERSION 3.9)
project(FdF)


set ( PROJECT_LINK_LIBS libft.a libmlx_Linux.a )
set (LINKED_LIBS  -lmlx -lXext -lX11 )



link_directories(libmlx libft)


include_directories(libmlx libft)



add_executable(FdF main.c get_next_line.c get_next_line.h read_map.c fdf.h)


target_link_libraries(FdF ${PROJECT_LINK_LIBS} -Werror -Wextra -Wall ${LINKED_LIBS})