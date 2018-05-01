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

LIBFT = libft

DIR_S = src

DIR_O = obj

HEADERS = include

SOURCES =	main.c movements.c keyboard.c read_map.c fdf.h line_drawing.c init_map.c put_image.c remove_map.c

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: obj $(NAME)

$(NAME): $(OBJS)
		@make -C $(LIBFT)
		@$(CC) -g $(FLAGS) -L $(LIBFT) -lft -o $@ $^ -lmlx -framework OpenGL -framework AppKit

obj:
		@mkdir -p obj

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADERS)/$(NAME).h
		@$(CC) -g $(FLAGS) -I $(HEADERS) -c -o $@ $<

norme:
		@make norme -C $(LIBFT)
		@echo "--------------------Checking header files fdf"
		@norminette ./$(HEADERS)
		@echo "--------------------Checking source files fdf"
		@norminette ./$(DIR_S)

clean:
		@rm -f $(OBJS)
		@make clean -C $(LIBFT)
		@rm -rf $(DIR_O)

fclean: clean
		@rm -f $(NAME)
		@make fclean -C $(LIBFT)

re: fclean all

.PHONY: all, obj, norme, clean, fclean, re
.NOTPARALLEL:  all, obj, norme, clean, fclean, re