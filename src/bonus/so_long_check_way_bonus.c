/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check_way_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:28:27 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	fill(char **tab, t_size size, t_point cur)
{
	if (cur.y < 0 || cur.y >= size.h || cur.x < 0 || cur.x >= size.w)
		return ;
	if (tab[cur.y][cur.x] != '0' && tab[cur.y][cur.x] != 'C'
		&& tab[cur.y][cur.x] != 'A')
		return ;
	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_point){cur.x - 1, cur.y});
	fill(tab, size, (t_point){cur.x + 1, cur.y});
	fill(tab, size, (t_point){cur.x, cur.y - 1});
	fill(tab, size, (t_point){cur.x, cur.y + 1});
}

static void	flood_fill(char **tab, t_size size, t_point begin)
{
	fill(tab, size, (t_point){begin.x - 1, begin.y});
	fill(tab, size, (t_point){begin.x + 1, begin.y});
	fill(tab, size, (t_point){begin.x, begin.y - 1});
	fill(tab, size, (t_point){begin.x, begin.y + 1});
}

int	check_matrix_way(char **m, t_point cur, t_size size)
{
	int	x;
	int	y;
	int	w;
	int	h;

	x = cur.x;
	y = cur.y;
	w = size.w;
	h = size.h;
	if ((x + 1 >= 0 && x + 1 < w) && (m[y][x + 1] == 'F' || m[y][x + 1] == 'A'
		|| m[y][x + 1] == 'P' || m[y][x + 1] == 'C' || m[y][x + 1] == 'E'))
		return (1);
	if ((x - 1 >= 0 && x - 1 < w) && (m[y][x - 1] == 'F' || m[y][x + 1] == 'A'
		|| m[y][x - 1] == 'P' || m[y][x - 1] == 'C' || m[y][x + 1] == 'E'))
		return (1);
	if ((y + 1 >= 0 && y + 1 < h) && (m[y + 1][x] == 'F' || m[y][x + 1] == 'A'
		|| m[y + 1][x] == 'P' || m[y + 1][x] == 'C' || m[y][x + 1] == 'E'))
		return (1);
	if ((y - 1 >= 0 && y - 1 < h) && (m[y - 1][x] == 'F' || m[y][x + 1] == 'A'
		|| m[y - 1][x] == 'P' || m[y - 1][x] == 'C' || m[y][x + 1] == 'E'))
		return (1);
	return (0);
}

t_point	find_in_matrix(char **matrix, char ch)
{
	int		l;
	int		c;

	l = 0;
	while (matrix[l])
	{
		c = 0;
		while (matrix[l][c])
		{
			if (matrix[l][c] == ch)
				return ((t_point){c, l});
			c++;
		}
		l++;
	}
	return ((t_point){-1, -1});
}

int	check_way(char *map)
{
	t_point	end;
	t_size	size;
	t_point	begin;
	char	**matrix;
	int		reference;

	size = size_map(map);
	matrix = str_to_matrix(map);
	begin = find_in_matrix(matrix, 'P');
	end = find_in_matrix(matrix, 'E');
	reset_matrix(matrix);
	flood_fill(matrix, size, begin);
	reference = check_matrix_reference_points(matrix, size);
	if (check_matrix_way(matrix, end, size)
		&& check_matrix_way(matrix, begin, size)
		&& reference)
	{
		free_matrix(matrix);
		return (1);
	}
	free_matrix(matrix);
	return (0);
}
