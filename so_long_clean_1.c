/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_clean_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:19:56 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_portal(t_wind *win)
{
	int	l;
	int	c;

	l = 0;
	while (l < 2)
	{
		c = 0;
		while (c < 9)
		{
			win->ptl[l][c].h = 0;
			win->ptl[l][c].w = 0;
			mlx_destroy_image(win->mlx, win->ptl[l][c].img_ptr);
			c++;
		}
		l++;
	}
}

void	clean_player(t_wind *win)
{
	int	m;
	int	l;
	int	c;

	m = 0;
	while (m < 2)
	{
		l = 0;
		while (l < 4)
		{
			c = 0;
			while (c < 9)
			{
				win->player[m][l][c].w = 0;
				win->player[m][l][c].h = 0;
				mlx_destroy_image(win->mlx, win->player[m][l][c].img_ptr);
				c++;
			}
			l++;
		}
		m++;
	}
}

void	init_portal(t_wind *win)
{
	int	l;
	int	c;

	l = 0;
	win->ptl_x = 0;
	win->ptl_y = 0;
	win->cur_ptl[0] = 0;
	win->cur_ptl[1] = 0;
	while (l < 2)
	{
		c = 0;
		while (c < 9)
		{
			win->ptl[l][c].h = 0;
			win->ptl[l][c].w = 0;
			win->ptl[l][c].img_ptr = NULL;
			c++;
		}
		l++;
	}
}

void	init_player(t_wind *win)
{
	int	m;
	int	l;
	int	c;

	m = 0;
	win->cur_play[0] = 0;
	win->cur_play[1] = 0;
	win->cur_play[2] = 0;
	while (m < 2)
	{
		l = 0;
		while (l < 4)
		{
			c = 0;
			while (c < 9)
			{
				win->player[m][l][c].w = 0;
				win->player[m][l][c].h = 0;
				win->player[m][l][c].img_ptr = NULL;
				c++;
			}
			l++;
		}
		m++;
	}
}

void	clean_command(t_wind *win)
{
	while (win->move != NULL)
		lstdel_front(&win->move);
}
