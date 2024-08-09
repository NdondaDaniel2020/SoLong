/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_wind.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:19:56 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*window*/
int	key_press(int keycode, t_wind *win)
{
	if (keycode == 65307)
		clean_and_exit(win);
	// if (keycode == 65363)
	// 	move_right(win);
	// if (keycode == 65361)
	// 	move_left(win);
	// if (keycode == 65362)
	// 	move_up(win);
	// if (keycode == 65364)
	// 	move_down(win);
	return (0);
}

int	clean_and_exit(t_wind *win)
{
	clean(win);
	if (win->map_matrix)
		free_matrix(win->map_matrix);
	if (win->map)
		free(win->map);
	if (win->bg_img.img_ptr)
		mlx_destroy_image(win->mlx, win->bg_img.img_ptr);
	if (win->win)
		mlx_destroy_window(win->mlx, win->win);
	if (win->mlx)
	{
		mlx_destroy_display(win->mlx);
		free(win->mlx);
	}
	exit(0);
}

int	clean(t_wind *win)
{
	if (win->star.img_ptr)
		mlx_destroy_image(win->mlx, win->star.img_ptr);
	if (win->block[0].img_ptr)
		mlx_destroy_image(win->mlx, win->block[0].img_ptr);
	if (win->block[1].img_ptr)
		mlx_destroy_image(win->mlx, win->block[1].img_ptr);
	if (win->ptl[0][0].img_ptr)
		clean_portal(win);
	if (win->player[0][0][0].img_ptr)
		clean_player(win);
	return (0);
}

void	connection(t_wind *win)
{
	mlx_key_hook(win->win, key_press, win);
	mlx_hook(win->win, 17, 0, clean_and_exit, win);
}
