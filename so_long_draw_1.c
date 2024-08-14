/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_draw_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:19:56 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
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
		if ((win->map_matrix[l][c] == '1') && is_border(win, l, c))
		{
			img = win->block[1].img_ptr;
			mlx_put_image_to_window(win->mlx, win->win, img, x, y);
		}
		if ((win->map_matrix[l][c] == '1') && !is_border(win, l, c))
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
			mlx_put_image_to_window(win->mlx, win->win, img, x + 10, y + 10);
		}
		x += 50;
		c++;
	}
}

static int	pos_enemy(t_wind *win)
{
	int		r;
	int		l;
	t_point	pos;

	r = 1;
	l = 1;
	pos = find_in_matrix(win->map_matrix, 'A');
	while (win->map_matrix[pos.y][pos.x + r] == '0')
		r++;
	while (win->map_matrix[pos.y][pos.x - l] == '0')
		l++;
	if (l < r)
		return (1);
	else
		return (0);
}

static void	draw_enemy(t_wind *win, int l, int y)
{
	int		c;
	int		x;
	int		pos;
	void	*img;

	c = 0;
	x = 0;
	while (win->map_matrix[l][c])
	{
		if (win->map_matrix[l][c] == 'A')
		{
			win->enemy->enmy_x = x;
			win->enemy->enmy_y = y + 19;
			pos = pos_enemy(win);
			win->enemy->cur_enmy[0] = pos;
			win->enemy->cur_enmy[1] = 0;
			win->enemy->cur_enmy[2] = 0;
			img = win->enemy->enemy[pos][0][0].img_ptr;
			mlx_put_image_to_window(win->mlx, win->win, img, x, y + 19);
		}
		x += 50;
		c++;
	}
}

void	draw_map(t_wind *win)
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
		draw_enemy(win, l, y);
		y += 50;
		l++;
	}
}
