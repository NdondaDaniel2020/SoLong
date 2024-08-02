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

void	master(t_wind *window)
{
	ft_printf("%s\n", window->map);
	window->map_matrix = str_to_matrix(window->map);
	add_background(window, window->map);
	connection(window);
	mlx_loop(window->mlx);
}

void	init(t_wind *window)
{
	window->w = 0;
	window->h = 0;
	window->mlx = NULL;
	window->win = NULL;
	window->bg = NULL;
	window->map = NULL;
	window->map_matrix = NULL;
}

int	main(int ac, char **av)
{
	t_wind	window;
	t_size	size;

	(void)ac;
	init(&window);
	window.map = get_map(av[1]);
	size = size_map(window.map);
	size.width *= 50;
	size.height *= 50;
	window.mlx = mlx_init();
	if (!window.mlx)
		clean_and_exit(&window);
	window.win = mlx_new_window(window.mlx, size.width, size.height, "solong");
	if (!window.win)
		clean_and_exit(&window);
	master(&window);
	return (0);
}
