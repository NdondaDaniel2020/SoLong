/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:28:27 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/31 12:39:18 by kali             ###   ########.fr       */
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

void	clean_occurrence(t_wind *win)
{
	int	i;
	int	len;

	i = 0;
	len = count_occurrence(win->map_matrix, '1');
	len += count_occurrence(win->map_matrix, 'C');
	while (i < len)
	{
		if (win->imgs[i].img_ptr)
			mlx_destroy_image(win->mlx, win->imgs[i].img_ptr);
		i++;
	}
	free(win->imgs);
}

int	width(char *map)
{
	int	i;
	int	aux;

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
	size.w = width(map);
	size.h = height(map);
	return (size);
}
