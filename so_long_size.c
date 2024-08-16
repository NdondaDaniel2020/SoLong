/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:28:27 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_border(t_wind *win, int l, int c)
{
	if ((l == 0) || (l == (win->size.h / 50) - 1))
		return (1);
	if (c == 0 || (c == (win->size.w / 50) - 1))
		return (1);
	return (0);
}

int	width(char *map)
{
	int	i;
	int	aux;

	aux = 0;
	while (*map)
	{
		i = 0;
		while (*map && *map != '\n')
		{
			++map;
			i++;
		}
		if (i == 0 || (aux != 0 && aux != i))
			return (0);
		aux = i;
		if (*map)
			++map;
	}
	return (aux);
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

static int	count_occurrence_str(char *str, char ch)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == ch)
			i++;
		++str;
	}
	return (i);
}

t_size	size_map(char *map)
{
	t_size	size;

	if (!map)
		return ((t_size){0, 0});
	size.w = width(map);
	size.h = height(map);
	if (count_occurrence_str(map, '\n') != size.h)
		size.h = 0;
	return (size);
}
