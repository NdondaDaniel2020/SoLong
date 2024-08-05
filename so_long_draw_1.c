/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_draw_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:19:56 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/31 10:32:07 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_wind *win)
{
	int		l;
	int		y;
	int		i;
	int		len;

	l = 0;
	y = 0;
	i = 0;
	len = count_occurrence(win->map_matrix, '1');
	len += count_occurrence(win->map_matrix, 'C');
	win->imgs = (t_image *)ft_calloc(len, sizeof(t_image));
	if (!win->imgs)
		clean_and_exit(win);
	while (win->map_matrix[l])
	{
		draw_line_map(win, l, y, &i);
		y += 50;
		l++;
	}
}

void	draw_line_map(t_wind *win, int l, int y, int *i)
{
	int		c;
	int		x;

	c = 0;
	x = 0;
	while (win->map_matrix[l][c])
	{
		if (win->map_matrix[l][c] == '1')
		{
			if (is_border(win, l, c))
				draw_tatami_2(win, x, y, i);
			else
				draw_tatami_1(win, x, y, i);
		}
		if (win->map_matrix[l][c] == 'C')
			draw_star(win, x, y, i);
		if (win->map_matrix[l][c] == 'E')
			draw_portal(win, x, y);
		if (win->map_matrix[l][c] == 'P')
			draw_player(win, x, y);
		x += 50;
		c++;
	}
}

void	draw_star(t_wind *win, int x, int y, int *i)
{
	int	w;
	int	h;

	x += 10;
	y += 10;
	w = win->imgs[*i].w;
	h = win->imgs[*i].h;
	win->imgs[*i].img_ptr = mlx_xpm_file_to_image(win->mlx, star(), &w, &h);
	if (!win->imgs)
		clean_and_exit(win);
	mlx_put_image_to_window(win->mlx, win->win, win->imgs[*i].img_ptr, x, y);
	(*i)++;
}

void	draw_tatami_1(t_wind *win, int x, int y, int *i)
{
	int	w;
	int	h;

	w = win->imgs[*i].w;
	h = win->imgs[*i].h;
	win->imgs[*i].img_ptr = mlx_xpm_file_to_image(win->mlx, tatame1(), &w, &h);
	if (!win->imgs)
		clean_and_exit(win);
	mlx_put_image_to_window(win->mlx, win->win, win->imgs[*i].img_ptr, x, y);
	(*i)++;
}

void	draw_tatami_2(t_wind *win, int x, int y, int *i)
{
	int	w;
	int	h;

	w = win->imgs[*i].w;
	h = win->imgs[*i].h;
	win->imgs[*i].img_ptr = mlx_xpm_file_to_image(win->mlx, tatame2(), &w, &h);
	if (!win->imgs)
		clean_and_exit(win);
	mlx_put_image_to_window(win->mlx, win->win, win->imgs[*i].img_ptr, x, y);
	(*i)++;
}
