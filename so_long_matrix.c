/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <nmatondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:28:27 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/19 15:35:34 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**cpy_matrix(char **zone, t_point size)
{
	int		l;
	int		c;
	char	**new;

	l = 0;
	new = malloc(sizeof(char *) * size.y);
	while (l < size.y)
	{
		c = 0;
		new[l] = malloc(size.x + 1);
		while (c < size.x)
		{
			new[l][c] = zone[l][c];
			c++;
		}
		new[l][size.x] = '\0';
		l++;
	}
	return (new);
}

char	*create_line_map(char *map, int size)
{
	int		i;
	char	*line_map;

	if (!map)
		return (NULL);
	i = 0;
	line_map = (char *)ft_calloc(size + 1, sizeof(char));
	if (!line_map)
		return (NULL);
	while (*map && *map != '\n' && i < size)
	{
		line_map[i] = *map;
		++map;
		i++;
	}
	line_map[i] = '\0';
	return (line_map);
}

char	**str_to_matrix(char *map)
{
	int		i;
	t_size	size;
	char	**map_matrix;

	if (!map)
		return (NULL);
	i = 0;
	size = size_map(map);
	map_matrix = (char **)ft_calloc(size.h + 1, sizeof(char *));
	if (!map_matrix)
		return (NULL);
	while (*map)
	{
		map_matrix[i] = create_line_map(map, size.w);
		while (*map && *map != '\n')
			++map;
		if (*map == '\n')
			++map;
		i++;
	}
	map_matrix[i] = NULL;
	return (map_matrix);
}

void	free_matrix(char **map_matrix)
{
	int	i;

	i = 0;
	while (map_matrix[i])
	{
		free(map_matrix[i]);
		i++;
	}
	free(map_matrix);
}
