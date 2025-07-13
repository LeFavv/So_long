# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/13 18:13:53 by vafavard          #+#    #+#              #
#    Updated: 2025/07/13 14:04:46 by vafavard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC_PATH = sources/
BONUS_PATH = sources/bonus_sources/
MLX_PATH = minilibx-linux/

BONUS_FILES = check_map_bonus.c collectibles_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c\
			 keyhook_bonus.c player_bonus.c so_long_bonus.c utils_bonus.c check_map_2_bonus.c\
			 check_map_3_bonus.c init_bonus.c itoa_bonus.c  image_bonus_new_version.c image_bonus_new_version_2.c\
			 get_image_bonus_1.c get_image_bonus_2.c get_image_bonus_3.c get_image_bonus_4.c


SRC_FILES = check_map.c collectibles.c get_next_line.c get_next_line_utils.c\
			image.c keyhook.c player.c so_long.c utils.c check_map_2.c check_map_3.c init.c init_image.c

SRC = $(addprefix $(SRC_PATH), $(SRC_FILES))
BONUS = $(addprefix $(BONUS_PATH), $(BONUS_FILES))
OBJS = $(patsubst %.c,%.o,$(SRC))
BONUS_OBJS = $(patsubst %.c,%.o,$(BONUS))
INCLUDES = -Iinclude
PRINTF_PATH = ft_printf
PRINTF_ARCHIVE = $(PRINTF_PATH)/libftprintf.a

all: $(NAME)

$(PRINTF_ARCHIVE):
	$(MAKE) -C $(PRINTF_PATH)

mlx:
	$(MAKE) -C $(MLX_PATH)

$(NAME): $(OBJS) $(PRINTF_ARCHIVE) mlx
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(PRINTF_ARCHIVE) -Lminilibx-linux -lmlx -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(BONUS_OBJS) $(PRINTF_ARCHIVE)
	$(CC) $(CFLAGS) $(INCLUDES) $(BONUS_OBJS) $(PRINTF_ARCHIVE) -Lminilibx-linux -lmlx -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz -o $(NAME_BONUS)

%.o: %.c
	@echo "Compiling $<"
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(PRINTF_PATH) clean
	rm -f $(OBJS) $(BONUS_OBJS)
	$(MAKE) -C $(MLX_PATH) clean

fclean: clean
	$(MAKE) -C $(PRINTF_PATH) fclean
	rm -f $(NAME) $(NAME_BONUS)
	$(MAKE) -C $(MLX_PATH) clean

re: fclean all

.PHONY: all clean fclean re bonus mlx
