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

static void	draw_block(t_wind *win, int l, int y)
{
	int		c;
	int		x;
	void	*img;

	c = 0;
	x = 0;
	while (win->map_matrix[l][c])
	{
		if ((in->map_matrix[l][c] == '1') && is_border(win, l, c))
		{
			img = win->block[1].img_ptr;
			mlx_put_image_to_window(win->mlx, win->win, img, x, y);
		}
		if ((in->map_matrix[l][c] == '1') && !is_border(win, l, c))
		{
			img = win->block[0].img_ptr;
			mlx_put_image_to_window(win->mlx, win->win, img, x, y);
		}
		x += 50;
		c++;
	}
}

static void	draw_star(t_wind *win, int l, int y)
{
	int		c;
	int		x;
	void	*img;

	c = 0;
	x = 0;
	while (win->map_matrix[l][c])
	{
		if (win->map_matrix[l][c] == 'C')
		{
			img = win->star.img_ptr;
			mlx_put_image_to_window(win->mlx, win->win, img, x, y);
		}
		x += 50;
		c++;
	}
}

void	draw_player(t_wind *win, int l, int y)
{
	int		c;
	int		x;
	void	*img;

	c = 0;
	x = 0;
	while (win->map_matrix[l][c])
	{
		if (win->map_matrix[l][c] == 'C')
		{
			
			img = win->star[].img_ptr;
			mlx_put_image_to_window(win->mlx, win->win, img, x, y);
		}
		x += 50;
		c++;
	}
}

static void	draw_portal(t_wind *win, int l, int y)
{
	int		c;
	int		x;
	void	*img;

	c = 0;
	x = 0;
	while (win->map_matrix[l][c])
	{
		if (win->map_matrix[l][c] == 'C')
		{
			img = win->star.img_ptr;
			mlx_put_image_to_window(win->mlx, win->win, img, x, y);
		}
		x += 50;
		c++;
	}
}

void	draw_map(t_wind *win, int l, int y)
{
	int		l;
	int		y;

	l = 0;
	y = 0;
	while (win->map_matrix[l])
	{
		draw_block(win, l, y);
		draw_star(win, l, y);
		draw_portal(win, l, y);
		draw_player(win, l, y);
		y += 50;
		l++;
	}
}

void	draw_empty(t_wind *win, int x, int y)
{
	void	*img;

	img = win->bg_img.img_ptr;
	mlx_put_image_to_window(win->mlx, win->win, img, x, y);
}
