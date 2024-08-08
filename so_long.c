/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:23:41 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	master(t_wind *win)
{
	win->map_matrix = str_to_matrix(win->map);
	upload_images(win);
	draw_map(win);
	connection(win);
	mlx_loop(win->mlx);
}

static void	init(t_wind *win)
{
	win->move = 0;
	win->mlx = NULL;
	win->win = NULL;
	win->map = NULL;
	init_portal(win);
	init_player(win);
	win->map_matrix = NULL;
	win->star.img_ptr = NULL;
	win->bg_img.img_ptr = NULL;
	win->block[0].img_ptr = NULL;
	win->block[1].img_ptr = NULL;
}

int	main(int ac, char **av)
{
	t_wind	win;

	(void)ac;
	init(&win);
	win.map = get_map(av[1]);
	win.size = size_map(win.map);
	win.size.w *= 50;
	win.size.h *= 50;
	win.mlx = mlx_init();
	if (!win.mlx)
		clean_and_exit(&win);
	win.win = mlx_new_window(win.mlx, win.size.w, win.size.h, "Ninja SoLong");
	if (!win.win)
		clean_and_exit(&win);
	master(&win);
	return (0);
}
