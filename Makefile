
all:
	gcc so_long.c so_long.h so_long_utils.c ./Libft/libft.a -L./minilibx-linux -lmlx -lXext -lX11 -lm -o so_long
	./so_long