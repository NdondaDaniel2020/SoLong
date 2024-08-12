/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_move_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 08:13:31 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	condition_move(t_wind *win, int x, int y)
{
	int			c;
	t_point		point;

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

void	get_star(t_wind *win, int x, int y)
{
	t_point	point;

	point = find_in_matrix(win->map_matrix, 'P');
	if (win->map_matrix[point.y + y][point.x + x] == 'C')
		update_star_count(win);
}

int	movement_blocked_right(t_wind *win)
{
	t_point	point;

	point = find_in_matrix(win->map_matrix, 'P');
	if ((win->map_matrix[point.y][point.x + 1] == '0'
		|| win->map_matrix[point.y][point.x + 1] == 'C')
		&& (win->map_matrix[point.y + 1][point.x] == '0'
		|| win->map_matrix[point.y + 1][point.x] == 'C')
		&& (win->map_matrix[point.y + 1][point.x + 1] == '0'
		|| win->map_matrix[point.y + 1][point.x + 1] == 'C'))
	{
		lstdel_front(&win->move);
		return (1);
	}
	return (0);
}

int	movement_blocked_left(t_wind *win)
{
	t_point	point;

	point = find_in_matrix(win->map_matrix, 'P');
	if ((win->map_matrix[point.y][point.x - 1] == '0'
		|| win->map_matrix[point.y][point.x - 1] == 'C')
		&& (win->map_matrix[point.y + 1][point.x - 1] == '0'
		|| win->map_matrix[point.y + 1][point.x - 1] == 'C')
		&& (win->map_matrix[point.y + 1][point.x] == '0'
		|| win->map_matrix[point.y + 1][point.x] == 'C'))
	{
		lstdel_front(&win->move);
		return (1);
	}
	return (0);
}
