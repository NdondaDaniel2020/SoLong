/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <nmatondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:41:56 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/19 15:44:58 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// # include "minilibx_mms/mlx.h"
// # include "minilibx_linux/mlx.h"
# include "libft/libft.h"
#include <fcntl.h> // Para open
#include <unistd.h> // Para read e close
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	get_line_number(char *map)
{
	int	i;

	i = 0;
	while (*map && *map != '\n')
	{
		i++;
		++map;
	}
	return (i);
}

int	get_column_number(char *map)
{
	int	i;

	i = 0;
	if (!map)
		return (0);
	while (*map)
	{
		if (*map == '\n')
			i++;
		++map;
	}
	i++;
	return (i);
}

int	check_line(char *map_line, int *column)
{
	static int	i=0;
	int	len;

	if (i == 0 || column == 0)
	{
		i++;
		*column--;
		if (!ft_findchar(map_line, '0'))
			return (1);
	}
	else
	{
		len = ft_strlen(map_line);
		if (map_line[0] == '1' && map_line[len-1] == '1')
			return (1);
	}
	free(map_line);
	return (0);
}

int	check_struct_map(char *map)
{
	char	*str;
	int		colu;
	int		i;

	colu = get_column_number(map);
	str = (char *)malloc(sizeof(char) * (get_line_number(map) + 1));
	if (!str)
		return (0);
	while (*map)
	{
		i = 0;
		while (*map && *map != '\n')
		{
			str[i++] = *map;
			++map;
		}
		str[i] = '\0';
		if (!check_line(str, &colu))
			return (0);
		if (*map)
			++map;
	}
	free(str);
	return (1);
}

int	check_map(char *map)
{
	int	column;
	int	line;
	int	valid;

	if (!map)
		return (0);
	valid = check_struct_map(map);
	column = get_column_number(map);
	line = get_line_number(map);
	if (valid && column > 3 && line > 3)
		return (1);
	return (0);
}

/*file*/
char	*read_file(int fd)
{
	char	*str;
	char	*aux;
	int		bytes_read;

	bytes_read = 1;
	if (!ft_initstr(&aux) || !ft_initstr(&str))
		return (NULL);
	while (bytes_read)
	{
		bytes_read = read(fd, aux, 1);
		if (bytes_read == -1)
		{
			free(aux);
			close(fd);
			return (NULL);
		}
		aux[bytes_read] = '\0';
		str = ft_strjoin_free(str, aux);
	}
	close(fd);
	free(aux);
	return (str);
}

char	*open_file(const char *filename)
{
	int		fd;
	char	*str;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	str = read_file(fd);
	return (str);
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
	while (*map && *map != '\n')
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
	int		line;
	int		column;
	char	**map_matrix;

	if (!map)
		return (NULL);
	i = 0;
	line = get_line_number(map);
	column = get_column_number(map);
	map_matrix = (char **)ft_calloc(line + 1, sizeof(char *));
	if (!map_matrix)
		return (NULL);
	while (*map)
	{
		map_matrix[i] = create_line_map(map, column);
		while (*map && *map != '\n')
			++map;
		++map;
		i++;
	}
	map_matrix[i] = '\0';
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

int	main(int ac, char **av)
{
	int		i;
	char	*map;
	char	**matrix_map;

	i = 0;
	map = open_file(av[1]);
	matrix_map = str_to_matrix(map);
	ft_printf("\n");
	while (matrix_map[i])
	{
		printf("%s\n", matrix_map[i]);
		i++;
	}
	free_matrix(matrix_map);
}
