# -lbsd
all:
	gcc so_long.c so_long_utils.c so_long.h ./Libft/libft.a -L./minilibx-linux -lmlx -lXext -lX11 -lm -o so_long
	./so_long map1.bar
	./so_long map2.bar

a:
	#gcc so_long.c so_long.h so_long_utils.c ./Libft/libft.a -L./minilibx-linux -lmlx -lXext -lX11 -lm -o so_long
	
m:
	gcc main.c ./Libft/libft.a -L./minilibx-linux -lmlx -lXext -lX11 -lm -o so_long
	./so_long map1.bar
	./so_long map2.bar

mm:
	gcc main.c ./Libft/libft.a -L./minilibx-linux -lmlx -lXext -lX11 -lm -o so_long
	./so_long map1.bar
	./so_long map2.bar