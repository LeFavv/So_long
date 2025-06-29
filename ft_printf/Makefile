# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/07 17:02:02 by vafavard          #+#    #+#              #
#    Updated: 2025/05/13 16:45:19 by vafavard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.
RM = rm -f
AR = ar
ARFLAGS = rcs
HEADER = ft_printf.h
SRCS	= 	ft_printf.c ft_print_p.c ft_print_hexa.c ft_print_chars.c ft_print_dec.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
			$(AR) $(ARFLAGS) $@ $^

%.o: %.c $(HEADER)
			$(CC) $(CFLAGS) -I. -c $< -o $@

clean: 
	$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
