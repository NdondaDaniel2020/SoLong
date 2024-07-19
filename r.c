/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <nmatondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:41:56 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/19 15:26:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
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


size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_findchar(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		++str;
	}
	return (0);
}


/*check map*/
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


int	main(int ac, char **av)
{
	char	*map="1111111111111111111111111111111111\n1E0000000000000C00000C000000000001\n1010010100100000101001000000010101\n1010010010101010001001000000010101\n1P0000000C00C0000000000000000000C1\n1111111111111111111111111111111111";
	int		line;
	int		colu;

	// check_map(map);
	printf("\n%i", check_map(av[1]));
	
	// printf("%i\n", percorer_mapa(map));
	// colu = get_column_number("1111111111111111111111111111111111");
	// printf("line=%i\ni", line);
	// printf("column=%i", colu);
}
