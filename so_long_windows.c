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
int	key_press(int keycode, void *param)
{
	(void)param;
	ft_printf("Tecla: %d\n", keycode);
	if (keycode == 65307)
		exit(0);
	return (0);
}

int	close_window(void *param)
{
	(void)param;
	exit(0);
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
