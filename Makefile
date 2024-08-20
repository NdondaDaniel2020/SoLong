# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
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
FILES = so_long_bonus.c \
		so_long_check_bonus.c \
		so_long_check_reference_bonus.c \
		so_long_check_way_bonus.c \
		so_long_clean_1_bonus.c \
		so_long_clean_2_bonus.c \
		so_long_draw_1_bonus.c \
		so_long_draw_2_bonus.c \
		so_long_enemy_mind_bonus.c \
		so_long_file_bonus.c \
		so_long_kill_bonus.c \
		so_long_lst_bonus.c \
		so_long_matrix_bonus.c \
		so_long_move_enemy_bonus.c \
		so_long_move_player_bonus.c \
		so_long_move_up_player_bonus.c \
		so_long_move_utils_1_bonus.c \
		so_long_move_utils_2_bonus.c \
		so_long_move_utils_3_bonus.c \
		so_long_name_file_1_bonus.c \
		so_long_name_file_2_bonus.c \
		so_long_name_file_3_bonus.c \
		so_long_size_bonus.c \
		so_long_update_1_bonus.c \
		so_long_update_2_bonus.c \
		so_long_update_score_bonus.c \
		so_long_upload_1_bonus.c \
		so_long_upload_2_bonus.c \
		so_long_validator_bonus.c \
		so_long_windows_bonus.c 

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
	@$(CC) $(FLAGS) $(NAME) $(LIBFT) -L$(PMLX) $(FMLX) -o $(RUN)

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
