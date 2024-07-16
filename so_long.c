/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <nmatondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:23:41 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/16 15:49:52 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_validator(char *file_name)
{
	int		fd;
	int		lin;
	int		col;
	char	*txt;
	
	lin = 0;
	col = 0;
	fd = open(file_name, O_RDONLY);
	if (fd != -1)
	{
		
		while (txt || lin == 0)
		{
			txt = get_next_line(fd);
			lin++;
		}
	}
	close(fd);
	
}

int	main(int ac, char **av)
{
	void	*mlx;
	
	mlx = mlx_init();
	
	mlx_loop(mlx);
}