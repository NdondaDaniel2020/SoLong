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

void	connection(t_wind *win)
{
	mlx_key_hook(win->win, key_press, win);
	mlx_hook(win->win, 17, 0, clean_and_exit, win);
}
