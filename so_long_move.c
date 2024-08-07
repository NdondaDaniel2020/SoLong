/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:19:56 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/31 10:32:07 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	condition_move(t_wind *win, int x, int y)
{
	t_point	point;

	point = find_in_matrix(win->map_matrix, 'P');
	ft_printf("(x%i y%i)\n", point.y, point.x);
	// ft_printf("   {%c}\n", win->map_matrix[point.x][point.y + y]);
	// ft_printf("{%c}", win->map_matrix[point.x][point.y - y]);
	// ft_printf("{%c}", win->map_matrix[point.x][point.y]);
	// ft_printf("{%c}\n", win->map_matrix[point.x + x][point.y]);
	// ft_printf("   {%c}\n", win->map_matrix[point.x - x][point.y]);
	if (win->map_matrix[point.y + y][point.x + x] == '0')
		return (1);
	if (win->map_matrix[point.y + y][point.x + x] == 'C')
		return (1);
	if (win->map_matrix[point.y + y][point.x + x] == 'E')
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
		move_player(win, win->play_x, win->play_y);
	}
}
