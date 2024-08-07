/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_draw_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:19:56 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/31 10:32:07 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	pos_player(t_wind *win)
{
	int		r;
	int		l;
	t_point	pos;

	r = 1;
	l = 1;
	pos = find_in_matrix(win->map_matrix, 'P');
	while (win->map_matrix[pos.y][pos.x + r] == '0')
		r++;
	while (win->map_matrix[pos.y][pos.x - l] == '0')
		l++;
	if (l > r)
		return (0);
	else
		return (1);
}

void	draw_player(t_wind *win, int l, int y)
{
	int		c;
	int		x;
	int		pos;
	void	*img;

	c = 0;
	x = 0;
	while (win->map_matrix[l][c])
	{
		if (win->map_matrix[l][c] == 'P')
		{
			pos = pos_player(win);
			img = win->player[pos].img_ptr;
			mlx_put_image_to_window(win->mlx, win->win, img, x, y);
		}
		x += 50;
		c++;
	}
}

static int	pos_portal(t_wind *win)
{
	int		r;
	int		l;
	t_point	pos;

	r = 1;
	l = 1;
	pos = find_in_matrix(win->map_matrix, 'E');
	while (win->map_matrix[pos.y][pos.x + r] == '0')
		r++;
	while (win->map_matrix[pos.y][pos.x - l] == '0')
		l++;
	if (l > r)
		return (1);
	else
		return (0);
}

void	draw_portal(t_wind *win, int l, int y)
{
	int		c;
	int		x;
	int		pos;
	void	*img;

	c = 0;
	x = 0;
	while (win->map_matrix[l][c])
	{
		if (win->map_matrix[l][c] == 'E')
		{
			pos = pos_portal(win);
			img = win->ptl[pos].img_ptr;
			mlx_put_image_to_window(win->mlx, win->win, img, x, y);
		}
		x += 50;
		c++;
	}
}
