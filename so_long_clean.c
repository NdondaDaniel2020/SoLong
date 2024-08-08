/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_clean.c                                    :+:      :+:    :+:   */
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
		while (l < 3)
		{
			c = 0;
			while (c < 9)
			{
				win->player[m][l][c].w = 0;
				win->player[m][l][c].h = 0;
				if (!win->player[m][l][c].img_ptr)
					mlx_destroy_image(win->mlx, win->player[m][l][c].img_ptr);
				c++;
			}
			l++;
		}
		m++;
	}
}
