/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check_way.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:28:27 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/31 10:30:59 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill(char **tab, t_point size, t_point cur)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x)
		return ;
	if (tab[cur.y][cur.x] != '0')
		return ;
	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_point){cur.x - 1, cur.y});
	fill(tab, size, (t_point){cur.x + 1, cur.y});
	fill(tab, size, (t_point){cur.x, cur.y - 1});
	fill(tab, size, (t_point){cur.x, cur.y + 1});
}

void	flood_fill(char **tab, t_point size, t_point begin)
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
	if ((x + 1 >= 0 && x + 1 < width) && (matrix[x + 1][y] == 'F'))
		return (1);
	if ((x - 1 >= 0 && x - 1 < width) && (matrix[x - 1][y] == 'F'))
		return (1);
	if ((y + 1 >= 0 && y + 1 < height) && (matrix[x][y + 1] == 'F'))
		return (1);
	if ((y - 1 >= 0 && y - 1 < height) && (matrix[x][y - 1] == 'F'))
		return (1);
	return (0);
}

int	check_way(char *map)
{
	t_point	end;
	t_point	size;
	t_point	begin;
	char	**area;

	size = size_map(map);
	matrix = str_to_matrix(map);
	area = cpy_matrix(matrix, size);
	begin = find_in_matrix(area, 'P');
	end = find_in_matrix(area, 'E');
	flood_fill(area, size, begin);
	if (check_way(area, end, (t_size){13, 5}))
		return (1);
	else
		return (0);
}

/*
int main(void)
{
	char**  area;
	t_point size;
	t_point begin;
	t_point f;

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