#include <stdlib.h>
#include <stdio.h>
// #include "flood_fill.h"

/**/
typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_size
{
	int			width;
	int 		height;
}	 			t_size;


void	fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x || tab[cur.y][cur.x] != to_fill)
		return;
	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
    fill(tab, size, (t_point){begin.x - 1, begin.y}, '0');
	fill(tab, size, (t_point){begin.x + 1, begin.y}, '0');
	fill(tab, size, (t_point){begin.x, begin.y - 1}, '0');
	fill(tab, size, (t_point){begin.x, begin.y + 1}, '0');
}
/**/

char** make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}

	return new;
}

t_point	find_in_matrix(char **matrix,char ch)
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
				return ((t_point){l, c});
			c++;
		}
		l++;
	}
	return ((t_point){-1, -1});
}

int	check_way(char **matrix, t_point cur, t_size size)
{
	if ((cur.x + 1 >= 0 && cur.x + 1 < size.width) && (matrix[cur.x + 1][cur.y] == 'F'))
		return (1);
	if ((cur.x - 1 >= 0 && cur.x - 1 < size.width) && (matrix[cur.x - 1][cur.y] == 'F'))
		return (1);
	if ((cur.y + 1 >= 0 && cur.y + 1 < size.width) && (matrix[cur.x][cur.y + 1] == 'F'))
		return (1);
	if ((cur.y - 1 >= 0 && cur.y - 1 < size.width) && (matrix[cur.x][cur.y - 1] == 'F'))
		return (1);
	return (0);
}

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

	area = make_area(zone, size);
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
