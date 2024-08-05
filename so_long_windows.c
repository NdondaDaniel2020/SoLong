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
int	key_press(int keycode, t_wind *win)
{
	ft_printf("Tecla: %d\n", keycode);
	(void)win;
	if (keycode == 65307)
		clean_and_exit(win);
	return (0);
}

int	clean_and_exit(t_wind *win)
{
	if (win->player[0][0][0].img_ptr)
		clean_player(win);
	if (win->ptl[0][0].img_ptr)
		clean_portal(win);
	if (win->imgs)
		clean_occurrence(win);
	if (win->map_matrix)
		free_matrix(win->map_matrix);
	if (win->map)
		free(win->map);
	if (win->bg)
		mlx_destroy_image(win->mlx, win->bg);
	if (win->win)
		mlx_destroy_window(win->mlx, win->win);
	if (win->mlx)
	{
		mlx_destroy_display(win->mlx);
		free(win->mlx);
	}
	exit(0);
}

t_size	size_image_background(char *map)
{
	t_size	size;

	size = size_map(map);
	if (size.w > 30)
		return ((t_size){2340, 1080});
	else if (size.w > 13)
		return ((t_size){1170, 540});
	else
		return ((t_size){650, 250});
}

void	connection(t_wind *win)
{
	mlx_key_hook(win->win, key_press, win);
	mlx_hook(win->win, 17, 0, clean_and_exit, win);
	mlx_loop_hook(win->mlx, (int (*)())update_portal_image, win);
}
