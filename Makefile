# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbirge-c <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/14 11:07:13 by dbirge-c          #+#    #+#              #
#    Updated: 2018/04/10 16:45:20 by dbirge-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = sdl_simple
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = .
SRCS =	main.c events.c update.c \
		render.c line_drawing.c colors.c	\
		maths_help.c vector2i.c vector2f.c	\
		frac_mandelbrot.c clamp.c \
		sdl_allocator.c app_allocator.c
OBJS = $(SRCS:.c=.o)

all: library $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) `sdl2-config --cflags --libs` -L ./libft -l ft -o $@

library:
	make -C ./libft

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $?

clean:
	rm -f $(OBJS)
	make -C ./libft clean

fclean: clean
	rm -f $(NAME)
	rm -f ./libft/libft.a

re: fclean all

.PHONY: all clean fclean re
