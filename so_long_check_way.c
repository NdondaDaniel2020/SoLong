/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check_way.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:28:27 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/31 12:40:10 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill(char **tab, t_size size, t_point cur)
{
	if (cur.y < 0 || cur.y >= size.height || cur.x < 0 || cur.x >= size.width)
		return ;
	if (tab[cur.y][cur.x] != '0')
		return ;
	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_point){cur.x - 1, cur.y});
	fill(tab, size, (t_point){cur.x + 1, cur.y});
	fill(tab, size, (t_point){cur.x, cur.y - 1});
	fill(tab, size, (t_point){cur.x, cur.y + 1});
}

void	flood_fill(char **tab, t_size size, t_point begin)
{
	fill(tab, size, (t_point){begin.x - 1, begin.y});
	fill(tab, size, (t_point){begin.x + 1, begin.y});
	fill(tab, size, (t_point){begin.x, begin.y - 1});
	fill(tab, size, (t_point){begin.x, begin.y + 1});
}

int	check_way_matrix(char **matrix, t_point cur, t_size size)
{
	int	x;
	int	y;
	int	width;
	int	height;

	x = cur.x;
	y = cur.y;
	width = size.width;
	height = size.height;
	if ((x + 1 >= 0 && x + 1 < width) && (matrix[y][x + 1] == 'F'))
		return (1);
	if ((x - 1 >= 0 && x - 1 < width) && (matrix[y][x - 1] == 'F'))
		return (1);
	if ((y + 1 >= 0 && y + 1 < height) && (matrix[y + 1][x] == 'F'))
		return (1);
	if ((y - 1 >= 0 && y - 1 < height) && (matrix[y - 1][x] == 'F'))
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

	size = size_map(map);
	matrix = str_to_matrix(map);
	begin = find_in_matrix(matrix, 'P');
	end = find_in_matrix(matrix, 'E');
	flood_fill(matrix, size, begin);
	if (check_way_matrix(matrix, end, size))
	{
		free_matrix(matrix);
		return (1);
	}
	free_matrix(matrix);
	return (0);
}

/*
int main(void)
{
	char**  area;
	t_point size;
	t_point begin;

	size = (t_point){13, 5};
	char *zone[] = {
		"1111111111111",
		"10000100000C1",
		"1000111111001",
		"1P0010E000001",
		"1111111111111",
	};

	area = cpy_matrix(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");

	begin = find_in_matrix(area, 'P');

	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);

	if (check_way(area, find_in_matrix(area, 'E'), (t_size){13, 5}))
		printf("\nvalido");
	else
		printf("\ninvalido");

	return (0);
}
*/