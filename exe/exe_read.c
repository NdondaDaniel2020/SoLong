/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <nmatondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:23:41 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/19 11:59:45 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "so_long.h"
# include "../minilibx_linux/mlx.h"

int	main(int ac, char **av)
{
	int		img_wid;
	int		img_hei;
	void	*img;
	char	*file;
	t_data	data;

	if (file == NULL)
		return (1);
	data.mlx = mlx_init();
	if (data.mlx == NULL)
	{
		free(file);
		return (1);
	}
	data.win = mlx_new_window(data.mlx, 800, 600, "Exemplo com Arquivo");
	if (data.win == NULL)
	{
		free(file);
		return (1);
	}
	mlx_string_put(data.mlx, data.win, 50, 50, 0xFFFFFF, file);

	img = mlx_png_file_to_image(data.mlx, "exe/Attack_2_1.png", &img_wid, &img_hei);
	mlx_put_image_to_window(data.mlx, data.win, img, 0, 0);

	// mlx_key_hook(data.win, key_press, &data);
	// mlx_hook(data.win, 17, 0, close_window, &data);

	mlx_loop(data.mlx);
	free(file);
	return (0);
}
