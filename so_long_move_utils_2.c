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
		|| win->map_matrix[point.y][point.x + 1] == 'C')
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
		|| win->map_matrix[point.y][point.x - 1] == 'C')
		&& (win->map_matrix[point.y + 1][point.x] == '1')
	)
	{
		win->diagonal_l = 1;
		return (1);
	}
	return (0);
}
