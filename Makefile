# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/13 18:13:53 by vafavard          #+#    #+#              #
#    Updated: 2025/07/01 14:36:26 by vafavard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC_PATH = sources/

SRC_FILES = check_map.c collectibles.c get_next_line.c get_next_line_utils.c\
			image.c keyhook.c player.c so_long.c utils.c check_map_2.c check_map_3.c

SRC = $(addprefix $(SRC_PATH), $(SRC_FILES))
OBJS = $(patsubst %.c,%.o,$(SRC))
INCLUDES = -Iinclude
PRINTF_PATH = ft_printf
PRINTF_ARCHIVE = $(PRINTF_PATH)/libftprintf.a

all: $(NAME)

$(PRINTF_ARCHIVE):
	$(MAKE) -C $(PRINTF_PATH)

$(NAME): $(OBJS) $(PRINTF_ARCHIVE)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(PRINTF_ARCHIVE) -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	@echo "Compiling $<"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(PRINTF_PATH) clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(PRINTF_PATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
