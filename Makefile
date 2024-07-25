# -lbsd # ./so_long map1.bar

make:
	cc so_long.c so_long_utils.c so_long_check.c so_long.h ./libft/*.c -L./minilibx_linux -lmlx -lXext -lX11 -lm -o so_long
	./so_long map/map1.txt
az:
	cc so_long.c so_long_utils.c so_long_check.c so_long.h ./libft/libft.a -L./minilibx_linux -lmlx -lXext -lX11 -lm -o so_long
al:
	gcc r.c -o r
	./r
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

n:
	norminette ./*.c ./*.h
