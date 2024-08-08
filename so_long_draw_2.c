/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_draw_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:19:56 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	pos_player(t_wind *win)
{
	int		r;
	int		l;
	t_point	pos;

	r = 1;
	l = 1;
	pos = find_in_matrix(win->map_matrix, 'P');
	while (win->map_matrix[pos.y][pos.x + r] == '0')
		r++;
	while (win->map_matrix[pos.y][pos.x - l] == '0')
		l++;
	if (l > r)
		return (0);
	else
		return (1);
}
