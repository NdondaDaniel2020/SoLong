/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_clean_2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:19:56 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	clean_enemy(t_wind *win)
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
			while (c < 6)
			{
				mlx_destroy_image(win->mlx,
					win->enemy->enemy[m][l][c].img_ptr);
				win->enemy->enemy[m][l][c].img_ptr = NULL;
				c++;
			}
			l++;
		}
		m++;
	}
	free(win->enemy);
	win->enemy = NULL;
}

void	clean_command_enemy(t_list **list)
{
	while (*list != NULL)
		lstdel_front(list);
}
