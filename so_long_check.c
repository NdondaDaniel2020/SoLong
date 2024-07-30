/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <nmatondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:28:27 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/19 15:35:34 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	int		column;
	t_size	size;

	if (!map)
		return (0);
	valid = check_struct_map(map);
	size = size_map(map);
	if (valid && size.width > 3 && size.height > 3)
		return (1);
	return (0);
}
