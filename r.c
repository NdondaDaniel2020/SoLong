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
	str = (char *)malloc(sizeof(char));
	str[0] = '\0';
	aux = (char *)malloc(sizeof(char) * 1);
	if (!aux)
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
		str = ft_strjoin(str, aux);
	}
	close(fd);
	return (str);
}

char	*open_file(const char *filename)
{
	int		fd;
	char	*str;

	str = NULL;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	str = read_file(fd);
	return (str);
}

char	**str_to_matr(char *str)
{
	int	i;
	char **map_matrix;

	map = (char **)ft_calloc(sizeof(char *) *);
	if (!str)
		return (0);
}

int	main(int ac, char **av)
{
	char *map;

	map = open_file(av[1]);
	printf("%s", map);
}
