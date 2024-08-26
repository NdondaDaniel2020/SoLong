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
BONUS = ./so_long_bonus
NAME = ./so_long
OBJ_DIR = ./obj/
LIBFT_DIR = ./libft
MLX_DIR = ./minilibx-linux
INCLUDE = ./include/
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a

FLAGS = -Wall -Wextra -Werror
FMLX = -l mlx -lXext -lX11 -lm

SRC_DIR = ./src/
SRC = so_long.c \
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

FILES = $(addprefix $(SRC_DIR),$(SRC))
OBJ	= $(SRC:%.c=%.o)

BONUS_DIR = $(SRC_DIR)bonus/
BSRC = so_long_bonus.c \
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

BFILES = $(addprefix $(BONUS_DIR),$(BSRC))
BOBJ = $(BSRC:%.c=%.o)

all:	$(NAME)

$(NAME):	$(OBJ_DIR) $(LIBFT) $(MLX)
	@$(CC) $(FLAGS) -c $(FILES) -I$(INCLUDE)
	@$(CC) $(FLAGS) $(OBJ) -I$(INCLUDE) $(LIBFT) -L$(MLX_DIR) $(FMLX) -o $(NAME)

bonus:	$(BONUS)

$(BONUS):	$(OBJ_DIR) $(LIBFT) $(MLX)
	@$(CC) $(FLAGS) -c $(BFILES) -I$(INCLUDE)
	$(CC) $(FLAGS) $(BOBJ) $(LIBFT) -I$(INCLUDE) -L$(MLX_DIR) $(FMLX) -o $(BONUS)

r:
	$(CC) $(FLAGS) $(BFILES) $(LIBFT) -L$(MLX_DIR) $(FMLX) -o $(NAME)

$(LIBFT):
	@make bonus -C $(LIBFT_DIR)

$(MLX):
	@make -C $(MLX_DIR)

n:
	python3 -m norminette .

clean:
	@/bin/rm -f $(OBJ) $(BOBJ)

fclean:	clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(BONUS)
	@make fclean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)

re:	fclean all

.PHONY: all bonus clean fclean re
