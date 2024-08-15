/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_move_utils_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 08:13:31 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	condition_move_top_right(t_wind *win, t_point point)
{
	if (win->move->next && *(char *)win->move->next->content == 'd'
		&& (win->map_matrix[point.y - 1][point.x] == '0'
		|| win->map_matrix[point.y - 1][point.x] == 'C')
		&& (win->map_matrix[point.y - 1][point.x + 1] == '0'
		|| win->map_matrix[point.y - 1][point.x + 1] == 'C')
		&& (win->map_matrix[point.y][point.x + 1] == '0'
		|| win->map_matrix[point.y][point.x + 1] == 'C'
		|| win->map_matrix[point.y][point.x + 1] == 'A')
		&& (win->map_matrix[point.y + 1][point.x] == '1')
	)
	{
		win->diagonal_r = 1;
		return (1);
	}
	return (0);
}

int	condition_move_top_left(t_wind *win, t_point point)
{
	if (win->move->next && *(char *)win->move->next->content == 'a'
		&& (win->map_matrix[point.y - 1][point.x] == '0'
		|| win->map_matrix[point.y - 1][point.x] == 'C')
		&& (win->map_matrix[point.y - 1][point.x - 1] == '0'
		|| win->map_matrix[point.y - 1][point.x - 1] == 'C')
		&& (win->map_matrix[point.y][point.x - 1] == '0'
		|| win->map_matrix[point.y][point.x - 1] == 'C'
		|| win->map_matrix[point.y][point.x - 1] == 'A')
		&& (win->map_matrix[point.y + 1][point.x] == '1')
	)
	{
		win->diagonal_l = 1;
		return (1);
	}
	return (0);
}

static void	change_diagonal_right(t_wind *win, t_point point)
{
	if (win->diagonal_r && win->move->next
		&& *(char *)win->move->next->content == 'd')
	{
		update_move_count(win);
		draw_empty(win, point.x * 50, (point.y - 1) * 50);
		draw_empty(win, (point.x + 1) * 50, (point.y - 1) * 50);
		if (win->play_x != ((win->play_x + 25) / 50) * 50)
			win->play_x = ((win->play_x + 25) / 50) * 50;
		win->map_matrix[point.y - 1][point.x] = '0';
		win->map_matrix[point.y - 1][point.x + 1] = 'P';
		win->diagonal_r = 0;
		win->diagonal_x = 0;
		clean_command(win);
	}
}

static void	change_diagonal_left(t_wind *win, t_point point)
{
	if (win->diagonal_l && win->move->next
		&& *(char *)win->move->next->content == 'a')
	{
		update_move_count(win);
		draw_empty(win, point.x * 50, (point.y - 1) * 50);
		draw_empty(win, (point.x - 1) * 50, (point.y - 1) * 50);
		if (win->play_x != ((win->play_x + 25) / 50) * 50)
			win->play_x = ((win->play_x + 25) / 50) * 50;
		win->map_matrix[point.y - 1][point.x] = '0';
		win->map_matrix[point.y - 1][point.x - 1] = 'P';
		win->diagonal_l = 0;
		win->diagonal_x = 0;
		clean_command(win);
	}
}

void	change_diagonal(t_wind *win, t_point point)
{
	change_diagonal_left(win, point);
	change_diagonal_right(win, point);
}
