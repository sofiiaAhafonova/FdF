cmake_minimum_required(VERSION 3.9)
project(FdF)

if(UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif()

# if(NOT LINUX) should work, too, if you need that
if(LINUX)
    message(STATUS ">>> Linux")
    link_directories(libmlx libft include)
    include_directories(libmlx libft include)
    set ( PROJECT_LINK_LIBS libft.a libmlx_Linux.a )
    set (LINKED_LIBS  -lXext -lX11 -lm )
    # linux stuff here
else()
    message(STATUS ">>> Not Linux")
    FIND_LIBRARY(OpenGL_LIBRARY OpenGL)
    INCLUDE_DIRECTORIES ( /System/Library/Frameworks )
    FIND_LIBRARY(COCOA_LIBRARY Cocoa)
    FIND_LIBRARY(GLUT_LIBRARY GLUT )
    MARK_AS_ADVANCED (COCOA_LIBRARY
                      GLUT_LIBRARY
                      OpenGL_LIBRARY)
    SET(EXTRA_LIBS ${COCOA_LIBRARY} ${GLUT_LIBRARY} ${OpenGL_LIBRARY})
    link_directories(minilibx_macos libft include)
    include_directories(minilibx_macos libft include)
    set ( PROJECT_LINK_LIBS libft.a libmlx.a )
    set (LINKED_LIBS  -lmlx)
    # stuff that should happen not on Linux
endif()

add_executable(FdF src/main.c src/movements.c src/keyboard.c src/read_map.c include/fdf.h
        src/line_drawing.c src/init_map.c src/put_image.c src/remove_map.c)
target_link_libraries(FdF ${PROJECT_LINK_LIBS} -Werror -Wextra -Wall ${LINKED_LIBS} ${EXTRA_LIBS})