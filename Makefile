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

LIBFT_DIR = libft
SRC_DIR = srcs/
OBJ_DIR = objs/
INC_DIR = -I includes/
SRCS =	main.c \
		events.c \
		update.c \
		render.c \
		line_drawing.c \
		colors.c \
		sdl_allocator.c \
		app_allocator.c \
		ft_math/maths_help.c \
		ft_math/interpolations.c \
		ft_math/vector2i.c \
		ft_math/vector2f.c \
		ft_math/clamp.c
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
NAME = sdl_simple
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SDL = `sdl2-config --cflags --libs`

all: library $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(SDL) $(OBJS) -L ./libft -l ft -o $@
	@echo "$(NAME) compiled"

library:
	@$(MAKE) -C libft

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) $(INCL) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C ./libft clean
	@echo "$(NAME) cleaned"

fclean: clean
	@rm -f $(NAME)
	@rm -f ./libft/libft.a

re: fclean all

.PHONY: all clean fclean re
