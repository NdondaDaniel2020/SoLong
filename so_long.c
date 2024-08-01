/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:23:41 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/31 12:14:30 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
int	key_press(int keycode, t_wind *window)
{
	ft_printf("Tecla: %d\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_image(window->mlx, window->img);
		mlx_destroy_window(window->mlx, window->win);
		free(window->mlx);
		exit(1);
	}
	return (0);
}

int	close_window(t_wind *window)
{
	mlx_destroy_image(window->mlx, window->img);
	mlx_destroy_window(window->mlx, window->win);
	free(window->img);
	free(window->mlx);
	exit(1);
	return (0);
}

t_size	size_image(char *map)
{
	t_size	size;

	size = size_map(map);
	if (size.width > 30)
		return ((t_size){2340, 1080});
	else if (size.width > 13)
		return ((t_size){1170, 540});
	else
		return ((t_size){650, 250});
}

void	add_background(t_wind window, char *map)
{
	int		x;
	int		y;
	char	*bg;
	t_size	size;
	t_size	size_img;

	(void)map;
	size = size_map(map);
	if (size.width > 30)
		bg = bg3();
	else if (size.width > 13)
		bg = bg2();
	else
		bg = bg1();
	size_img = size_image(map);
	x = ((50 * size.width) - size_img.width) / 2;
	y = ((50 * size.height) - size_img.height) / 2;
	window.img = mlx_xpm_file_to_image(window.mlx, bg, &window.w, &window.h);
	mlx_put_image_to_window(window.mlx, window.win, window.img, x, y);
}

void	connection(t_wind window)
{
	mlx_key_hook(window.win, key_press, &window);
	mlx_hook(window.win, 17, 0, close_window, &window);
}
*/

int	main(int ac, char **av)
{
	char	*map;
	t_wind	window;
	t_size	size;

	(void)ac;
	(void)av;
	map = get_map(av[1]);
	// size = size_map(map);
	
	size.width = 50;
	size.height = 50;
	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, size.width, size.height, "solong");
	
	// ft_printf("%i %i\n%s\n", size.width, size.height, map);
	ft_printf("%s\n", map);
	
	// add_background(window, map);
	// connection(window);
	
	mlx_loop(window.mlx);
	
	free(map);
	
	return (0);
}
