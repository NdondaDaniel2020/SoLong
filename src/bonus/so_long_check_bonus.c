/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:28:27 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	check_char_in_map(char *map_line)
{
	int	o;
	int	p;
	int	e;
	int	c;
	int	a;

	o = ft_findchar(map_line, '0');
	p = ft_findchar(map_line, 'P');
	e = ft_findchar(map_line, 'E');
	c = ft_findchar(map_line, 'C');
	a = ft_findchar(map_line, 'A');
	if (!o && !p && !e && !c && !a)
		return (1);
	return (0);
}

/*check map*/
static int	check_line(char *map_line, int *column)
{
	static int	i = 0;
	int			len;

	if (i == 0 || column == 0)
	{
		i++;
		*column = *column - 1;
		if (check_char_in_map(map_line))
			return (1);
	}
	else
	{
		i++;
		*column = *column - 1;
		len = ft_strlen(map_line);
		if (map_line[0] == '1' && map_line[len - 1] == '1')
			return (1);
	}
	free(map_line);
	return (0);
}

static int	check_struct_map(char *map)
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

int	check_map(char *map)
{
	int		valid;
	t_size	size;

	if (!map)
		return (0);
	size = size_map(map);
	if (size.w <= 2 || size.h <= 2)
		return (0);
	valid = check_struct_map(map);
	if (valid && size.w >= 2 && size.h >= 2)
		return (1);
	return (0);
}
