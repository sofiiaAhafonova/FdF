cmake_minimum_required(VERSION 3.9)
project(FdF)


if (LINUX)
    set ( PROJECT_LINK_LIBS libft.a libmlx_Linux.a )
    set (LINKED_LIBS  -lmlx -lXext -lX11 )
else()
    set ( PROJECT_LINK_LIBS libft.a)
    set (LINKED_LIBS  -lmlx)
endif ()

if (LINUX)
    link_directories(libmlx libft)
else()
    link_directories(libft)
endif ()

if (LINUX)
    include_directories(libmlx libft)
else()
    include_directories(libft)
endif ()


add_executable(FdF main.c get_next_line.c get_next_line.h read_map.c fdf.h)


target_link_libraries(FdF ${PROJECT_LINK_LIBS} -Werror -Wextra -Wall ${LINKED_LIBS})