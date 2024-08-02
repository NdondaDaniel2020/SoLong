/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:23:41 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/31 12:14:30 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validator_format(char *name)
{
	if (ft_strnstr(name, ".ber", ft_strlen(name)) == NULL)
	{
		ft_printf("Formato do mapa errado\nFormato recomendado *.ber\n");
		exit(1);
	}
}

void	validator_map(char *map)
{
	if (!check_duplicate(map) || !check_map(map) || !check_way(map))
	{
		ft_printf("Mapa invalido\n");
		free(map);
		exit(1);
	}
}

char	*get_map(char *name)
{
	char	*map;

	if (!name)
	{
		ft_printf("Mapa não encontrado\n");
		exit (1);
	}
	validator_format(name);
	map = open_file(name);
	if (map == NULL)
	{
		ft_printf("Arquivo %s inexistente\n", name);
		exit(1);
	}
	validator_map(map);
	return (map);
}
