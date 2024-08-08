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
		so_long_windows.c \
		so_long_validator.c \
		so_long_name_file_1.c \
		so_long_name_file_2.c \
		so_long_check_reference.c \
		so_long_draw_1.c \
		so_long_draw_2.c \
		so_long_upload.c \
		so_long_move.c

FLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a
MLX = ./minilibx_linux
FMLX = -l mlx -lXext -lX11 -lm


all:	$(NAME)

$(NAME):	$(LIBFT) $(MLX)
	$(CC) $(FLAGS) $(FILES) $(LIBFT) -L$(MLX) $(FMLX) -o $(NAME)

$(LIBFT):
	make bonus -C ./libft

$(MLX):
	make -C ./minilibx_linux

n:
	python3 -m norminette ./*.c ./*.h

clean:
	@/bin/rm -f $(NAME)

fclean:	clean
	@/bin/rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
