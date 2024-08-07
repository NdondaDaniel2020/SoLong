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
CC = cc
RUN = ./so_long
NAME = $(RUN).a
H = ./so_long.h

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
		so_long_name_file_3.c \
		so_long_check_reference.c \
		so_long_draw_1.c \
		so_long_draw_2.c \
		so_long_draw_3.c

OBJ = $(FILES:.c=.o)
FLAGS = -Wall -Wextra -Werror

PLIBF = ./libft
LIBFT = $(PLIBF)/libft.a

PMLX = ./minilibx_linux
MLX= $(PMLX)/libmlx_Linux.a

FMLX = -l mlx -lXext -lX11 -lm

all:	$(NAME)

$(NAME):	$(LIBFT) $(MLX)
	$(CC) $(FLAGS) -c $(FILES)
	ar rc $(NAME) $(OBJ)

$(LIBFT):
	make bonus -C $(PLIBF)

$(MLX):
	make -C $(PMLX)

run:	$(RUN) $(NAME)

$(RUN):
	make clean
	$(CC) $(FLAGS) $(H) $(NAME) $(LIBFT) -L$(PMLX) $(FMLX) -o $(RUN)

n:
	python3 -m norminette ./*.c ./*.h

clean:
	@/bin/rm -f $(OBJ)

fclean:	clean
	/bin/rm -f $(NAME)
	@ make fclean -C libft
	@ make clean -C minilibx_linux

re:	fclean all

.PHONY: all clean fclean re