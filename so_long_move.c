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

static int	condition_move(t_wind *win, int x, int y)
{
	int		c;
	t_point	point;

	c = count_occurrence(win->map_matrix, 'C');
	point = find_in_matrix(win->map_matrix, 'P');
	if (win->map_matrix[point.y + y][point.x + x] == '0')
		return (1);
	if (win->map_matrix[point.y + y][point.x + x] == 'C')
		return (1);
	if (win->map_matrix[point.y + y][point.x + x] == 'E' && c == 0)
		clean_and_exit(win);
	return (0);
}

void	move_left(t_wind *win)
{
	t_point	point;

	if (condition_move(win, -1, 0))
	{
		win->cur_play = 0;
		point = find_in_matrix(win->map_matrix, 'P');
		win->map_matrix[point.y][point.x] = '0';
		win->map_matrix[point.y][point.x - 1] = 'P';
		draw_empty(win, win->play_x, win->play_y);
		win->play_x -= 50;
		win->move += 1;
		ft_printf("move: %i\n", win->move);
		move_player(win, win->play_x, win->play_y);
	}
}

void	move_right(t_wind *win)
{
	t_point	point;

	if (condition_move(win, 1, 0))
	{
		win->cur_play = 1;
		point = find_in_matrix(win->map_matrix, 'P');
		win->map_matrix[point.y][point.x] = '0';
		win->map_matrix[point.y][point.x + 1] = 'P';
		draw_empty(win, win->play_x, win->play_y);
		win->play_x += 50;
		win->move += 1;
		ft_printf("move: %i\n", win->move);
		move_player(win, win->play_x, win->play_y);
	}
}

void	move_up(t_wind *win)
{
	t_point	point;

	if (condition_move(win, 0, -1))
	{
		point = find_in_matrix(win->map_matrix, 'P');
		win->map_matrix[point.y][point.x] = '0';
		win->map_matrix[point.y - 1][point.x] = 'P';
		draw_empty(win, win->play_x, win->play_y);
		win->play_y -= 50;
		win->move += 1;
		ft_printf("move: %i\n", win->move);
		move_player(win, win->play_x, win->play_y);
	}
}

void	move_down(t_wind *win)
{
	t_point	point;

	if (condition_move(win, 0, 1))
	{
		point = find_in_matrix(win->map_matrix, 'P');
		win->map_matrix[point.y][point.x] = '0';
		win->map_matrix[point.y + 1][point.x] = 'P';
		draw_empty(win, win->play_x, win->play_y);
		win->play_y += 50;
		win->move += 1;
		ft_printf("move: %i\n", win->move);
		move_player(win, win->play_x, win->play_y);
	}
}
