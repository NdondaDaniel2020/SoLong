/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_wind.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:19:56 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/31 10:32:07 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*window*/
int	key_press(int keycode, t_wind *window)
{
	ft_printf("Tecla: %d\n", keycode);
	(void)window;
	if (keycode == 65307)
		clean_and_exit(window);
	return (0);
}

int clean_and_exit(t_wind *window)
{
	if (window->bg)
    {
        mlx_destroy_image(window->mlx, window->bg);
    }
    if (window->win)
    {
        mlx_destroy_window(window->mlx, window->win);
    }
    if (window->mlx)
    {
        mlx_destroy_display(window->mlx);
        free(window->mlx);
    }
    exit(0);
}

t_size	size_image_background(char *map)
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

void	add_background(t_wind *window, char *map)
{
	int		x;
	int		y;
	char	*bg;
	t_size	size;
	t_size	size_bg;

	(void)map;
	size = size_map(map);
	if (size.width > 30)
		bg = bg3();
	else if (size.width > 13)
		bg = bg2();
	else
		bg = bg1();
	size_bg = size_image_background(map);
	x = ((50 * size.width) - size_bg.width) / 2;
	y = ((50 * size.height) - size_bg.height) / 2;
	window->bg = mlx_xpm_file_to_image(window->mlx, bg, &window->w, &window->h);
	if (!window->bg)
		clean_and_exit(window);
	mlx_put_image_to_window(window->mlx, window->win, window->bg, x, y);
}

void	connection(t_wind *window)
{
	mlx_key_hook(window->win, key_press, &window);
	mlx_hook(window->win, 17, 0, clean_and_exit, &window);
}
