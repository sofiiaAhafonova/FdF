#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sahafono <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/01 15:31:54 by sahafono          #+#    #+#              #
#    Updated: 2018/05/01 15:33:05 by sahafono         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc

NAME = fdf

FLAGS = -Wall -Wextra -Werror

I_DIR = ./include

S_DIR = ./src

O_DIR = ./obj

EXTENSIONS = $(addprefix $(I_DIR)/,$(EXT))

EXT =   fdf.h\

HEADERS =-I$(I_DIR)

SOURCES =  main.c movements.c keyboard.c read_map.c line_drawing.c init_map.c put_image.c remove_map.c


SRCS = $(addprefix $(S_DIR)/,$(SOURCES))

OBJS = $(addprefix $(O_DIR)/,$(SOURCES:.c=.o))

all: obj $(NAME)

$(NAME): $(OBJS) $(EXTENSIONS)
	$(CC) -o $(NAME) $(OBJS) $(FLAGS) $(HEADERS)

obj:
	mkdir -p $(O_DIR)

$(O_DIR)/%.o: $(S_DIR)/%.c $(EXTENSIONS)
	$(CC) -c -o $@ $< $(FLAGS) $(HEADERS)

clean:
	rm -f $(OBJS)
	rm -rf $(O_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, obj, clean, fclean, re
.NOTPARALLEL:  all, obj, clean, fclean, re
.SILENT:
