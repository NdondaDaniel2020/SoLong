/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_move_enemy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 08:13:31 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	condition_move_enemy(t_wind *win, int x, int y)
{
	t_point		point;

	point = find_in_matrix(win->map_matrix, 'A');
	if (win->map_matrix[point.y + y][point.x + x] == '0')
		return (1);
	return (0);
}

static void	move_down_enemy(t_wind *win)
{
	t_point	point;

	if (win->enemy->move && *(char *)win->enemy->move->content == '2')
	{
		if (condition_move_enemy(win, 0, 1))
		{
			win->enemy->cur_enmy[1] = 0;
			win->enemy->enmy_y += 10;
			if ((win->enemy->enmy_y - 19) % 50 == 0)
			{
				point = find_in_matrix(win->map_matrix, 'A');
				win->map_matrix[point.y][point.x] = '0';
				win->map_matrix[point.y + 1][point.x] = 'A';
				lstdel_front(&win->enemy->move);
			}
		}
		else
			lstdel_front(&win->enemy->move);
	}
}

static void	move_right_enemy(t_wind *win)
{
	t_point	point;

	if (win->enemy->move && *(char *)win->enemy->move->content == '6')
	{
		if (condition_move_enemy(win, 1, 0))
		{
			win->enemy->cur_enmy[0] = 1;
			win->enemy->cur_enmy[1] = 1;
			win->enemy->enmy_x += 5;
			if (win->enemy->enmy_x % 50 == 0)
			{
				point = find_in_matrix(win->map_matrix, 'A');
				win->map_matrix[point.y][point.x] = '0';
				win->map_matrix[point.y][point.x + 1] = 'A';
				win->enemy->cur_enmy[1] = 0;
				lstdel_front(&win->enemy->move);
			}
		}
		else
			lstdel_front(&win->enemy->move);
	}
}

static void	move_left_enemy(t_wind *win)
{
	t_point	point;

	if (win->enemy->move && *(char *)win->enemy->move->content == '4')
	{
		if (condition_move_enemy(win, -1, 0))
		{
			win->enemy->cur_enmy[0] = 0;
			win->enemy->cur_enmy[1] = 1;
			win->enemy->enmy_x -= 5;
			if (win->enemy->enmy_x % 50 == 0)
			{
				point = find_in_matrix(win->map_matrix, 'A');
				win->map_matrix[point.y][point.x] = '0';
				win->map_matrix[point.y][point.x - 1] = 'A';
				win->enemy->cur_enmy[1] = 0;
				lstdel_front(&win->enemy->move);
			}
		}
		else
			lstdel_front(&win->enemy->move);
	}
}

void	move_enemy(t_wind *win)
{
	atack_enemy(win);
	death_enemy(win);
	move_down_enemy(win);
	move_right_enemy(win);
	move_left_enemy(win);
}
