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

void	add_background(t_wind *win)
{
	int		w;
	int		h;
	void	*bg;

	w = win->bg_img.w;
	h = win->bg_img.h;
	bg = background();
	win->bg_img.img_ptr = mlx_xpm_file_to_image(win->mlx, bg, &w, &h);
}

void	master(t_wind *win)
{
	ft_printf("%s\n", win->map);
	win->map_matrix = str_to_matrix(win->map);
	add_background(win);
	draw_map(win);
	connection(win);
	mlx_loop(win->mlx);
}

void	init(t_wind *win)
{
	win->mlx = NULL;
	win->win = NULL;
	win->map = NULL;
	win->imgs = NULL;
	win->map_matrix = NULL;
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
