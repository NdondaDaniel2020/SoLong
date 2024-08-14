/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_move_up.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 08:13:31 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	change_diagonal(t_wind *win, t_point point)
{
	if (win->diagonal_r && win->move->next
		&& *(char *)win->move->next->content == 'd')
	{
		draw_empty(win, point.x * 50, (point.y - 1) * 50);
		draw_empty(win, (point.x + 1) * 50, (point.y - 1) * 50);
		win->play_x = ((win->play_x + 25) / 50) * 50;
		win->map_matrix[point.y - 1][point.x] = '0';
		win->map_matrix[point.y - 1][point.x + 1] = 'P';
		win->diagonal_r = 0;
		clean_command(win);
	}
	if (win->diagonal_l && win->move->next
		&& *(char *)win->move->next->content == 'a')
	{
		draw_empty(win, point.x * 50, (point.y - 1) * 50);
		draw_empty(win, (point.x - 1) * 50, (point.y - 1) * 50);
		win->play_x = ((win->play_x + 25) / 50) * 50;
		win->map_matrix[point.y - 1][point.x] = '0';
		win->map_matrix[point.y - 1][point.x - 1] = 'P';
		win->diagonal_l = 0;
		clean_command(win);
	}
}

static void	change_x_in_top(t_wind *win)
{
	if (win->diagonal_r && win->move->next
		&& *(char *)win->move->next->content == 'd')
		win->play_x += 8;
	if (win->diagonal_l && win->move->next
		&& *(char *)win->move->next->content == 'a')
		win->play_x -= 8;
}

static void	get_star_in_top(t_wind *win)
{
	if (win->diagonal_r && win->move->next
		&& *(char *)win->move->next->content == 'd')
		get_star(win, 1, -1);
	if (win->diagonal_l && win->move->next
		&& *(char *)win->move->next->content == 'a')
		get_star(win, -1, -1);
	get_star(win, 0, -1);
}

static void	condition_diagonal(t_wind *win, t_point point)
{
	if (!win->diagonal_r)
		condition_move_top_right(win, point);
	if (!win->diagonal_l)
		condition_move_top_left(win, point);
}

void	move_up(t_wind *win)
{
	t_point	point;

	if (win->move && *(char *)win->move->content == 'w')
	{
		point = find_in_matrix(win->map_matrix, 'P');
		if (condition_move(win, 0, -1))
		{
			win->cur_play[1] = 2;
			win->play_y -= 5;
			condition_diagonal(win, point);
			change_x_in_top(win);
			if (win->play_y % 50 == 0)
			{
				update_move_count(win);
				get_star_in_top(win);
				win->map_matrix[point.y][point.x] = '0';
				win->map_matrix[point.y - 1][point.x] = 'P';
				change_diagonal(win, point);
				win->cur_play[1] = 0;
				lstdel_front(&win->move);
			}
		}
		else
			lstdel_front(&win->move);
	}
}
