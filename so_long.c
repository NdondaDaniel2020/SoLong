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

void    validator_format(char *name)
{
    if (ft_strnstr(name, ".ber", ft_strlen(name)) == NULL)
    {
        ft_printf("Formato do mapa errado\nFormato recomendado *.ber");
        exit(1);
    }
}

void	validator_map(char *map)
{
	ft_printf("Mapa invalido %i \n", check_way(map));
	// if (!check_map(map) || !check_way(map))
	// {
	// 	ft_printf("Mapa invalido");
	// 	free(map);
	// 	exit(1);
	// }
}

int	main(int ac, char **av)
{
	char	*map;
	
	(void)ac;
    validator_format(av[1]);
	map = open_file(av[1]);
	// validator_map(map);

	// check_way(map);

	ft_printf("%s\n", map);
	free(map);
	return (0);
}
