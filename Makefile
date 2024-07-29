# -lbsd # ./so_long map1.bar                                                          
libft = ./libft/libft.a

all: $(libft)
	gcc so_long.c so_long_utils.c ./libft/libft.a -L./minilibx_linux -l mlx -lXext -lX11 -lm -o so_long
	@echo -e "\n"
	./so_long map/map1.txt | cat -e
	@echo -e "\n"

$(libft):
	make -C libft/

al:
	gcc r.c -o r
	./r
a:
	gcc so_long.c so_long.h so_long_utils.c ./Libft/libft.a -L./minilibx-linux -lmlx -lXext -lX11 -lm -o so_long                                                      
        
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

pull:
	@git pull
	make -C libft/
	all
	make fclean -C libft/

push:
	git add .; git commit -m "caso resolvido" ;git push

to_fill;
	gcc flood_fill.c -o flood_fill && ./flood_fill 
