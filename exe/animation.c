/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <nmatondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:41:56 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/19 11:15:47 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx_linux/mlx.h"
#include "../minilibx_mms/mlx.h"
#include <fcntl.h> // Para open
#include <unistd.h> // Para read e close
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define FRAME_RATE 10 // Define a taxa de frames por segundo (FPS)

typedef struct s_
{
    void    *mlx;
    void    *win;
    void    *imgs[4][10]; // Array para armazenar as imagens
    int     img_width;
    int     img_height;
    int     current_img;
} t_data;

int g_direction = 0;

// Função que alterna as imagens
int update_image(t_data *data) 
{
    mlx_clear_window(data->mlx, data->win);
    data->current_img = (data->current_img + 1) % 9; // Alterna entre 0, 1 e 2
    mlx_put_image_to_window(data->mlx, data->win, data->imgs[g_direction][data->current_img], 0, 0);
	usleep(100000);
    return 0;
}

int	key_press(int keycode, void *param)
{
	(void)param;
	printf("Tecla: %d\n", keycode);
	if (keycode == 65307) /*ESC no Linux*/
		exit(0);
    if (keycode == 65361)
        g_direction = 0;
    if (keycode == 65362)
        g_direction = 1;
    if (keycode == 65364)
        g_direction = 2;
    if (keycode == 65363)
        g_direction = 3;
	return (0);
}

int main(void)
{
    t_data  data;

    // Inicializa a conexão com o servidor gráfico
    data.mlx = mlx_init();
    if (data.mlx == NULL)
	{
        fprintf(stderr, "Erro ao inicializar MiniLibX\n");
        return (1);
    }

    // Cria uma janela de 800x600 pixels
    data.win = mlx_new_window(data.mlx, 800, 600, "Animacao de Imagens");
    if (data.win == NULL)
	{
        fprintf(stderr, "Erro ao criar a janela\n");
        return (1);
    }

    // Carrega as imagens a partir de arquivos XPM
    data.imgs[0][0] = mlx_xpm_file_to_image(data.mlx, "../img/block/block_1.xpm", &data.img_width, &data.img_height);
    data.imgs[0][1] = mlx_xpm_file_to_image(data.mlx, "../img/block/block_2.xpm", &data.img_width, &data.img_height);
    data.imgs[0][2] = mlx_xpm_file_to_image(data.mlx, "../img/block/block_3.xpm", &data.img_width, &data.img_height);
    data.imgs[0][3] = mlx_xpm_file_to_image(data.mlx, "../img/block/block_4.xpm", &data.img_width, &data.img_height);
    data.imgs[0][4] = mlx_xpm_file_to_image(data.mlx, "../img/block/block_5.xpm", &data.img_width, &data.img_height);
    data.imgs[0][5] = mlx_xpm_file_to_image(data.mlx, "../img/block/block_6.xpm", &data.img_width, &data.img_height);
    data.imgs[0][6] = mlx_xpm_file_to_image(data.mlx, "../img/block/block_7.xpm", &data.img_width, &data.img_height);
    data.imgs[0][7] = mlx_xpm_file_to_image(data.mlx, "../img/block/block_8.xpm", &data.img_width, &data.img_height);
    data.imgs[0][8] = mlx_xpm_file_to_image(data.mlx, "../img/block/block_9.xpm", &data.img_width, &data.img_height);
    data.imgs[0][9] = mlx_xpm_file_to_image(data.mlx, "../img/block/block_10.xpm", &data.img_width, &data.img_height);

    data.imgs[1][0] = mlx_xpm_file_to_image(data.mlx, "../img/Kunoichi-back/Idle_1.xpm", &data.img_width, &data.img_height);
    data.imgs[1][1] = mlx_xpm_file_to_image(data.mlx, "../img/Kunoichi-back/Idle_2.xpm", &data.img_width, &data.img_height);
    data.imgs[1][2] = mlx_xpm_file_to_image(data.mlx, "../img/Kunoichi-back/Idle_3.xpm", &data.img_width, &data.img_height);
    data.imgs[1][3] = mlx_xpm_file_to_image(data.mlx, "../img/Kunoichi-back/Idle_4.xpm", &data.img_width, &data.img_height);
    data.imgs[1][4] = mlx_xpm_file_to_image(data.mlx, "../img/Kunoichi-back/Idle_5.xpm", &data.img_width, &data.img_height);
    data.imgs[1][5] = mlx_xpm_file_to_image(data.mlx, "../img/Kunoichi-back/Idle_6.xpm", &data.img_width, &data.img_height);
    data.imgs[1][6] = mlx_xpm_file_to_image(data.mlx, "../img/Kunoichi-back/Idle_7.xpm", &data.img_width, &data.img_height);
    data.imgs[1][7] = mlx_xpm_file_to_image(data.mlx, "../img/Kunoichi-back/Idle_8.xpm", &data.img_width, &data.img_height);
    data.imgs[1][8] = mlx_xpm_file_to_image(data.mlx, "../img/Kunoichi-back/Idle_9.xpm", &data.img_width, &data.img_height);
    data.imgs[1][9] = mlx_xpm_file_to_image(data.mlx, "../img/Kunoichi-back/Idle_1.xpm", &data.img_width, &data.img_height);

    data.imgs[2][0] = mlx_xpm_file_to_image(data.mlx, "../img/portal-back/portal_1.xpm", &data.img_width, &data.img_height);
    data.imgs[2][1] = mlx_xpm_file_to_image(data.mlx, "../img/portal-back/portal_2.xpm", &data.img_width, &data.img_height);
    data.imgs[2][2] = mlx_xpm_file_to_image(data.mlx, "../img/portal-back/portal_3.xpm", &data.img_width, &data.img_height);
    data.imgs[2][3] = mlx_xpm_file_to_image(data.mlx, "../img/portal-back/portal_4.xpm", &data.img_width, &data.img_height);
    data.imgs[2][4] = mlx_xpm_file_to_image(data.mlx, "../img/portal-back/portal_5.xpm", &data.img_width, &data.img_height);
    data.imgs[2][5] = mlx_xpm_file_to_image(data.mlx, "../img/portal-back/portal_6.xpm", &data.img_width, &data.img_height);
    data.imgs[2][6] = mlx_xpm_file_to_image(data.mlx, "../img/portal-back/portal_7.xpm", &data.img_width, &data.img_height);
    data.imgs[2][7] = mlx_xpm_file_to_image(data.mlx, "../img/portal-back/portal_8.xpm", &data.img_width, &data.img_height);
    data.imgs[2][8] = mlx_xpm_file_to_image(data.mlx, "../img/portal-back/portal_9.xpm", &data.img_width, &data.img_height);
    data.imgs[2][9] = mlx_xpm_file_to_image(data.mlx, "../img/portal-back/portal_1.xpm", &data.img_width, &data.img_height);

    data.imgs[3][0] = mlx_xpm_file_to_image(data.mlx, "../img/portal-front/portal_1.xpm", &data.img_width, &data.img_height);
    data.imgs[3][1] = mlx_xpm_file_to_image(data.mlx, "../img/portal-front/portal_2.xpm", &data.img_width, &data.img_height);
    data.imgs[3][2] = mlx_xpm_file_to_image(data.mlx, "../img/portal-front/portal_3.xpm", &data.img_width, &data.img_height);
    data.imgs[3][3] = mlx_xpm_file_to_image(data.mlx, "../img/portal-front/portal_4.xpm", &data.img_width, &data.img_height);
    data.imgs[3][4] = mlx_xpm_file_to_image(data.mlx, "../img/portal-front/portal_5.xpm", &data.img_width, &data.img_height);
    data.imgs[3][5] = mlx_xpm_file_to_image(data.mlx, "../img/portal-front/portal_6.xpm", &data.img_width, &data.img_height);
    data.imgs[3][6] = mlx_xpm_file_to_image(data.mlx, "../img/portal-front/portal_7.xpm", &data.img_width, &data.img_height);
    data.imgs[3][7] = mlx_xpm_file_to_image(data.mlx, "../img/portal-front/portal_8.xpm", &data.img_width, &data.img_height);
    data.imgs[3][8] = mlx_xpm_file_to_image(data.mlx, "../img/portal-front/portal_9.xpm", &data.img_width, &data.img_height);
    data.imgs[3][9] = mlx_xpm_file_to_image(data.mlx, "../img/portal-front/portal_1.xpm", &data.img_width, &data.img_height);


    // Verifica se as imagens foram carregadas corretamente
    for (int i = 0; i < 3; i++)
	{
        if (data.imgs[i] == NULL) {
            fprintf(stderr, "Erro ao carregar a imagem %d\n", i + 1);
            return (1);
        }
    }

    data.current_img = 0; // Inicia com a primeira imagem

    // Configura o loop para atualizar a imagem a cada intervalo (FRAME_RATE)
    mlx_loop_hook(data.mlx, (int (*)())update_image, &data);
    mlx_key_hook(data.win, key_press, &data);

    // Loop para manter a janela aberta até que o usuário a feche
    mlx_loop(data.mlx);

    return (0);
}
