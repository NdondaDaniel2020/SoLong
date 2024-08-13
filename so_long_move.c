/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 08:13:31 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void change_diagonal(t_wind *win, t_point point)
{
	if (win->move->next && *(char *)win->move->next->content == 'd')
	{
		win->play_x = ((win->play_x  + 25) / 50) * 50;
		win->map_matrix[point.y - 1][point.x] = '0';
		win->map_matrix[point.y - 1][point.x + 1] = 'P';
		win->diagonal_r = 0;
		clean_command(win);
	}
}

// static void	change_x_in_top(t_wind *win)
// {
// 	if (win->move->next && *(char *)win->move->next->content == 'd')
// 		win->play_x += 8;
// }

static void	get_star_in_top(t_wind *win)
{
	if (win->move->next && *(char *)win->move->next->content == 'd')
		get_star(win, 1, -1);
	get_star(win, 0, -1);
}

static void	move_up(t_wind *win)
{
	t_point	point;

	if (win->move && *(char *)win->move->content == 'w')
	{
		point = find_in_matrix(win->map_matrix, 'P');
		if (condition_move(win, 0, -1))
		{
			win->cur_play[1] = 2;
			win->play_y -= 5;
			ft_printf("{{{{{{%i}}}}}}\n", condition_move_top(win, point));
			if (win->move->next && *(char *)win->move->next->content == 'd')
				win->play_x += 8;
			// change_x_in_top(win);
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

static void	move_down(t_wind *win)
{
	t_point	point;

	if (win->move && *(char *)win->move->content == 's')
	{
		if (condition_move(win, 0, 1))
		{
			win->cur_play[1] = 0;
			win->play_y += 10;
			if (win->play_y % 50 == 0)
			{
				update_move_count(win);
				point = find_in_matrix(win->map_matrix, 'P');
				get_star(win, 0, 1);
				win->map_matrix[point.y][point.x] = '0';
				win->map_matrix[point.y + 1][point.x] = 'P';
				lstdel_front(&win->move);
			}
		}
		else
			lstdel_front(&win->move);
	}
}

static void	move_right(t_wind *win)
{
	t_point	point;

	if (win->move && *(char *)win->move->content == 'd')
	{
		if (movement_blocked_right(win))
			move_down(win);
		else if (condition_move(win, 1, 0))
		{
			win->cur_play[0] = 1;
			win->cur_play[1] = 1;
			win->play_x += 5;
			if (win->play_x % 50 == 0)
			{
				update_move_count(win);
				point = find_in_matrix(win->map_matrix, 'P');
				get_star(win, 1, 0);
				win->map_matrix[point.y][point.x] = '0';
				win->map_matrix[point.y][point.x + 1] = 'P';
				win->cur_play[1] = 0;
				lstdel_front(&win->move);
			}
		}
		else
			lstdel_front(&win->move);
	}
}

static void	move_left(t_wind *win)
{
	t_point	point;

	if (win->move && *(char *)win->move->content == 'a')
	{
		if (movement_blocked_left(win))
			move_down(win);
		else if (condition_move(win, -1, 0))
		{
			win->cur_play[0] = 0;
			win->cur_play[1] = 1;
			win->play_x -= 5;
			if (win->play_x % 50 == 0)
			{
				update_move_count(win);
				point = find_in_matrix(win->map_matrix, 'P');
				get_star(win, -1, 0);
				win->map_matrix[point.y][point.x] = '0';
				win->map_matrix[point.y][point.x - 1] = 'P';
				win->cur_play[1] = 0;
				lstdel_front(&win->move);
			}
		}
		else
			lstdel_front(&win->move);
	}
}

void	move_player(t_wind *win)
{
	move_up(win);
	move_down(win);
	move_right(win);
	move_left(win);
}
