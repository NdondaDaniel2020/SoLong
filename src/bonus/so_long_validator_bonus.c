/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:23:41 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	inf_error(int p, int e, int a, int ex)
{
	int	i;

	i = 1;
	if (p != 1 || e != 1 || a != 1 || ex != 0)
	{
		i = 0;
		ft_printf("Error\n");
	}
	if (p == 0)
		ft_printf("No player.\n");
	if (p > 1)
		ft_printf("Many player.\n");
	if (e == 0)
		ft_printf("No door.\n");
	if (e > 1)
		ft_printf("Many door.\n");
	if (a == 0)
		ft_printf("No enemy.\n");
	if (a > 1)
		ft_printf("Many enemy.\n");
	if (ex != 0)
		ft_printf("Unknown character.\n");
	return (i);
}

int	check_duplicate(char *map)
{
	int	p;
	int	e;
	int	a;
	int	ex;

	p = 0;
	e = 0;
	a = 0;
	ex = 0;
	while (*map)
	{
		if (*map == 'E')
			e++;
		if (*map == 'P')
			p++;
		if (*map == 'A')
			a++;
		if (*map != 'P' && *map != 'E' && *map != '0'
			&& *map != '1' && *map != 'C' && *map != 'A' && *map != '\n')
			ex++;
		++map;
	}
	if (inf_error(p, e, a, ex))
		return (1);
	return (0);
}


static void	validator_format(char *name, char *format)
{
	int	len_n;
	int	len_f;

	len_n = ft_strlen(name);
	len_f = ft_strlen(format);
	while (format[len_f - 1] && name[len_n - 1] == format[len_f - 1])
	{
		len_f--;
		len_n--;
	}
	if (len_f != 0)
	{
		ft_printf("Error\nMap format recommended format *.ber\n");
		exit(1);
	}
}

static void	validator_map(char *map)
{
	if (!check_duplicate(map))
	{
		free(map);
		exit(1);
	}
	if (!check_map(map))
	{
		ft_printf("Error\nMap size error\n");
		free(map);
		exit(1);
	}
	if (!ft_findchar(map, 'C'))
	{
		ft_printf("Error\nNo collectibles\n");
		free(map);
		exit(1);
	}
}

char	*get_map(char *name)
{
	char	*map;

	if (!name)
	{
		ft_printf("Error\nMap not found\n");
		exit (1);
	}
	validator_format(name, ".ber");
	map = open_file(name);
	if (map == NULL)
	{
		ft_printf("Error\nFile %s does not exist\n", name);
		exit(1);
	}
	validator_map(map);
	if (!check_way(map))
	{
		ft_printf("Error\nNo escape path\n");
		free(map);
		exit(1);
	}
	return (map);
}
