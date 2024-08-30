/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_move_utils_3_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 08:13:31 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	atack_enemy(t_wind *win)
{
	if (win->enemy->move && *(char *)win->enemy->move->content == '5')
	{
		win->enemy->cur_enmy[1] = 2;
		win->enemy->frame += 5;
		if (win->enemy->frame % 50 == 0)
		{
			lstdel_front(&win->enemy->move);
			win->enemy->cur_enmy[1] = 0;
		}
	}
}

void	death_enemy(t_wind *win)
{
	if (win->enemy->move && *(char *)win->enemy->move->content == '0')
	{
		win->enemy->cur_enmy[1] = 3;
		win->enemy->frame += 5;
		if (win->enemy->frame % 30 == 0)
		{
			lstdel_front(&win->enemy->move);
			win->enemy->is_dead = 1;
			clean_command_enemy(&win->enemy->move);
		}
	}
}

void	condition_reverse_enemy(t_wind *win, int y)
{
	t_point	p_enemy;

	p_enemy = find_in_matrix(win->map_matrix, 'A');
	if ((y + '0') != *(char *)win->enemy->move->content
		&& (*(char *)win->enemy->move->content == '4'
		|| *(char *)win->enemy->move->content == '6'))
	{
		win->map_matrix[p_enemy.y][p_enemy.x] = '0';
		if (y == 4)
			win->map_matrix[p_enemy.y][p_enemy.x + 1] = 'A';
		else
			win->map_matrix[p_enemy.y][p_enemy.x - 1] = 'A';
	}
}
