/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:28:27 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

/*check map*/
int	check_line(char *map_line, int *column)
{
	static int	i = 0;
	int			len;

	if (i == 0 || column == 0)
	{
		i++;
		(*column)--;
		if (!ft_findchar(map_line, '0'))
			return (1);
	}
	else
	{
		len = ft_strlen(map_line);
		if (map_line[0] == '1' && map_line[len - 1] == '1')
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

	colu = height(map);
	str = (char *)malloc(sizeof(char) * (width(map) + 1));
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

int	check_duplicate(char *map)
{
	int	p;
	int	e;

	p = 0;
	e = 0;
	while (*map)
	{
		if (*map == 'E')
			e++;
		if (*map == 'P')
			p++;
		++map;
	}
	if (p == 1 && e == 1)
		return (1);
	return (0);
}

int	check_map(char *map)
{
	int		valid;
	t_size	size;

	if (!map)
		return (0);
	valid = check_struct_map(map);
	size = size_map(map);
	if (valid && size.w >= 3 && size.h >= 3)
		return (1);
	return (0);
}
