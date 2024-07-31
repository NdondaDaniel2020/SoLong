# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kali <kali@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/06 01:32:20 by nmatondo          #+#    #+#              #
#    Updated: 2024/07/31 11:03:16 by kali             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# so_long.h
CC = gcc
NAME = ./so_long
FILES = so_long.c \
		so_long_check_way.c \
		so_long_size.c \
		so_long_check.c \
		so_long_file.c \
		so_long_matrix.c \
		so_long_wind.c

FLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a
MLX = ./minilibx_linux
FMLX = -l mlx -lXext -lX11 -lm

all:	$(NAME)

$(NAME):	$(LIBFT) $(MLX)
	$(CC) $(FLAGS) $(FILES) -L$(LIBFT) -L$(MLX) $(FMLX) -o $(NAME)

$(LIBFT):
	make bonus -C ./libft

$(MLX):
	make -C ./minilibx_linux

clean:
	@/bin/rm -f $(OBJS)

fclean:	clean
	@/bin/rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re