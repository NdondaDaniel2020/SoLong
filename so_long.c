/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <nmatondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:23:41 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/18 14:31:09 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	void	*mlx;
	void	*win;
	
	int		width = 500;
	int		height = 230;

	void *img;           // Ponteiro para a imagem
	int img_width;       // Largura da imagem
    int img_height;      // Altura da imagem
	
	char *map;

	mlx = mlx_init();
	win = mlx_new_window(mlx, width, height, "./so_long");

	map = read_map(av[1]);	
	// img = mlx_xpm_file_to_image(mlx, "img/caixa.xpm", &img_width, &img_height);
	
	// mlx_put_image_to_window(mlx, win, img, 0, 0);
	
	mlx_key_hook(win, key_press, NULL);
	mlx_hook(win, 17, 0, close_window, NULL);
	
	mlx_loop(mlx);
}