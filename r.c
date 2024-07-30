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

typedef struct	s_size
{
	int			width;
	int 		height;
}	 			t_size;

int	width(char *map)
{
	int	i;
	int	aux;

	i = 0;
	aux = 0;
	while (*map)
	{
	    i = 0;
		while (*map != '\0' && *map != '\n')
		{
			i++;
			++map;
		}
		if (*map == '\0' && i == aux)
	        return (i);
	    else if (aux == 0 || i == aux)
	    {
		    aux = i;
		    ++map;
	    }
	}
	return (0);
}

int	height(char *map)
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

t_size	size_map(char *map)
{
	t_size	size;

	if (!map)
		return ((t_size){0, 0});
	size.width = width(map);
	size.height = height(map);
	return (size);
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
/**/


/**/
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
	t_size	size;
	char	**map_matrix;

	if (!map)
		return (NULL);
	i = 0;
	size = size_map(map);
	map_matrix = (char **)ft_calloc(size.height + 1, sizeof(char *));
	if (!map_matrix)
		return (NULL);
	while (*map)
	{
		map_matrix[i] = create_line_map(map, size.width);
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
/**/

int	main(int ac, char **av)
{
	int		i;
	char	*map;
	char	**matrix_map;

	i = 0;
	map = open_file(av[1]);
	// ft_printf("%s", map);
	matrix_map = str_to_matrix(map);

	// free_matrix(matrix_map);
}

