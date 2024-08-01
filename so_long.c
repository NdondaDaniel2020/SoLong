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

int	main(int ac, char **av)
{
	char	*map;
	t_wind	window;
	t_size	size;

	(void)ac;
	map = get_map(av[1]);
	size = size_map(map);
	size.width *= 50;
	size.height *= 50;
	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, size.width, size.height, "solong");
	ft_printf("%i %i\n%s\n", size.width, size.height, map);
	add_background(window, map);
	connection(window);
	mlx_loop(window.mlx);
	free(map);
	return (0);
}
