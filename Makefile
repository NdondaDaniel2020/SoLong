# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    header.txt                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/06 01:32:20 by nmatondo          #+#    #+#              #
#    Updated: 2024/08/07 16:44:49 by nmatondo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
RUN = ./so_long
NAME = $(RUN).a
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
		so_long_upload_1.c \
		so_long_upload_2.c \
		so_long_move.c \
		so_long_clean.c \
		so_long_update.c

OBJ = $(FILES:.c=.o)

FLAGS = -Wall -Wextra -Werror

PLIBFT = ./libft
LIBFT = $(PLIBFT)/libft.a

PMLX = ./minilibx-linux
MLX = $(PMLX)/libmlx.a

FMLX = -l mlx -lXext -lX11 -lm

all:	$(NAME)

$(NAME):	$(LIBFT) $(MLX)
	@$(CC) $(FLAGS) -c $(FILES)
	@ar rc $(NAME) $(OBJ)

run: $(NAME)
	@make clean
	@$(CC) $(FLAGS) $(NAME) $(LIBFT) -L$(PMLX) $(FMLX) -o $(RUN)

r:
	$(CC) $(FLAGS) $(FILES) $(LIBFT) -L$(PMLX) $(FMLX) -o $(RUN)

$(LIBFT):
	make bonus -C $(PLIBFT)

$(MLX):
	make -C $(PMLX)

n:
	python3 -m norminette ./*.c ./*.h

clean:
	@/bin/rm -f $(OBJ)

fclean:	clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(RUN)
	@make fclean -C $(PLIBFT)
	@make clean -C $(PMLX)

re:	fclean all

.PHONY: all clean fclean re
