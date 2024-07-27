#include <stdlib.h>
#include <stdio.h>
// #include "flood_fill.h"

/**/
typedef struct	s_point
{
	int x;
	int y;
} t_point;

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
    // printf("{x-%i y-%i} {%c = %i}\n\n", begin.x, begin.y, tab[begin.y][begin.x], tab[begin.y][begin.x]);
	// fill(tab, size, begin, '0');
    // fill(tab, size, begin, tab[begin.y][begin.x]);
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

int main(void)
{
	t_point size = {13, 5};
	char *zone[] = {
		"1111111111111",
		"10000000000C1",
		"1000111111001",
		"1P0010E000001",
		"1111111111111",
	};

	char**  area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");

	t_point begin = {7, 3};
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
}
