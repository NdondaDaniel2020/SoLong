/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <nmatondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:23:41 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/19 09:08:22 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(void)
{
	int 	img_width; 
    int		img_height;
	void	*img;
    char	*file;
	t_data	data;

	file = open_file("map/map1.txt");
	if (file == NULL)
        return (1);

    data.mlx = mlx_init();
    if (data.mlx == NULL)
	{
        fprintf(stderr, "Erro ao inicializar MiniLibX\n");
        free(file);
        return (1);
    }

    data.win = mlx_new_window(data.mlx, 800, 600, "Exemplo com Arquivo");
    if (data.win == NULL)
	{
        fprintf(stderr, "Erro ao criar a janela\n");
        free(file);
        return (1);
    }

    mlx_string_put(data.mlx, data.win, 50, 50, 0xFFFFFF, file);	
	img = mlx_xpm_file_to_image(data.mlx, "img/terra.xpm", &img_width, &img_height);
	mlx_put_image_to_window(data.mlx, data.win, img, 0, 0);
	
	mlx_key_hook(data.win, key_press, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);

    mlx_loop(data.mlx);
    free(file);
    return (0);
}
