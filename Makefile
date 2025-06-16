# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/13 18:13:53 by vafavard          #+#    #+#              #
#    Updated: 2025/06/16 13:34:11 by vafavard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long
# SRC = $(addprefix src/, main.c utils.c draw.c map_parser.c path_checker.c game_utils.c map_parser_utils.c free.c)
# GNL_SRC = $(addprefix gnl/, gnl.c gnl_utils.c)
# PRINTF_SRC = $(addprefix ft_printf/, ft_print_c.c ft_print_d.c ft_print_p.c ft_print_s.c ft_print_u.c ft_print_x.c ft_printf.c)
SRC = so_long.c

OBJ := $(SRC:%.c=%.o)
# GNL_OBJ := $(GNL_SRC:%.c=%.o)
# PRINTF_OBJ := $(PRINTF_SRC:%.c=%.o)

CC = gcc
CCFLAGS = -Wextra -Wall -Werror

all: $(NAME)

# $(NAME): $(OBJ) $(GNL_OBJ) $(PRINTF_OBJ)
    # $(CC) $(CCFLAGS) $^ -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
$(NAME): $(OBJ)
	$(CC) $(CCFLAGS) $^ -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	gcc $(CCFLAGS) -Imlx -Iincludes -c $< -o $@

# clean:
# 	rm -f $(OBJ) $(GNL_OBJ) $(PRINTF_OBJ)
clean:
	rm -f $(OBJ) $(GNL_OBJ) $(PRINTF_OBJ)


fclean: clean
	make clean -C mlx/
	rm -f $(NAME)

re : fclean all
