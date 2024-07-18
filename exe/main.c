/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <nmatondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 08:45:18 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/18 11:48:25 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Definição da largura e altura da janela
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

// Função de saída, utilizada para fechar a janela e sair do programa
int close_window(void *param)
{
    (void)param;
    exit(0);
    return (0);
}

int main()
{
    void *mlx;           // Ponteiro para a conexão com o sistema gráfico
    void *window;        // Ponteiro para a janela criada
    int x, y;            // Coordenadas dos pixels
	void *img[4];           // Ponteiro para a imagem
	int img_width;       // Largura da imagem
    int img_height;      // Altura da imagem


	// width = (50 * get_column_number(av[1]));
	// height = (50 * get_line_number(av[1]));
	
	// if (!map_validator(av[1]))
	// 	return (1);
	

    mlx = mlx_init();
    window = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "./so_long");
	int i = 0;
	while (i < 4)
	{
		img[i] = mlx_xpm_file_to_image(mlx, "img/block49x49.xpm", &img_width, &img_height);
		mlx_put_image_to_window(mlx, window, img[i], 100*i, 100*i);
		i++;
	}
    mlx_hook(window, 17, 0, close_window, NULL);
    mlx_loop(mlx);
    return (0);
}

// gcc -o so_long main.c -L./minilibx-linux -lmlx -lXext -lX11 -lm
