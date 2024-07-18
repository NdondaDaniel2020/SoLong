#include "so_long.h"
#include <mlx.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// Definição da largura e altura da janela
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

/* validator size */
int get_line_number(char *file_name)
{
    int fd;
    int i;
    char *aux;

    i = 0;
    fd = open(file_name, O_RDONLY);
    if (fd < 0)
        return 0; // Falha ao abrir o arquivo
    aux = get_next_line(fd);
    if (!aux)
        return 0;
    while (aux)
    {
        free(aux); // Libera a linha lida
        aux = get_next_line(fd);
        i++;
    }
    close(fd);
    return i;
}

int get_column_number(char *file_name)
{
    int fd;
    int i;
    char *aux;

    i = 0;
    fd = open(file_name, O_RDONLY);
    if (fd < 0)
        return 0; // Falha ao abrir o arquivo
    aux = get_next_line(fd);
    if (!aux)
        return 0;
    while (aux[i] && aux[i] != '\n')
        i++;
    free(aux); // Libera a linha lida
    close(fd);
    return i;
}

/* validator map */
int loop_map(char *txt)
{
    int len;

    len = 0;
    if (!txt)
        return 0;
    len = ft_strlen(txt);
    if (txt[0] == '0' || txt[len - 2] == '0')
        return 0;
    return 1;
}

int map_validator_value(char *file_name)
{
    int fd;
    int line;
    int line_map;
    char *txt;

    line = 0;
    fd = open(file_name, O_RDONLY);
    if (fd < 0)
        return 0; // Falha ao abrir o arquivo
    txt = get_next_line(fd);
    if (ft_findchar(txt, '0'))
    {
        free(txt);
        return 0;
    }
    line_map = get_line_number(file_name);
    while (line != (line_map - 1))
    {
        txt = get_next_line(fd);
        if (!loop_map(txt))
        {
            free(txt);
            return 0;
        }
        free(txt);
        line++;
    }
    txt = get_next_line(fd);
    if (ft_findchar(txt, '0'))
    {
        free(txt);
        return 0;
    }
    free(txt);
    close(fd);
    return 1;
}

int map_validator(char *file_name)
{
    int column;
    int line;
    int valid;

    if (!file_name)
        return 0;
    valid = map_validator_value(file_name);
    column = get_column_number(file_name);
    line = get_line_number(file_name);
    if (valid && column > 6 && line > 4)
        return 1;
    return 0;
}

// Função de saída, utilizada para fechar a janela e sair do programa
int close_window(void *param)
{
    (void)param;
    exit(0);
    return (0);
}

int main(int ac, char **av)
{
    if (ac < 2)
    {
        fprintf(stderr, "Usage: %s <map_file>\n", av[0]);
        return 1;
    }

    if (!map_validator(av[1]))
    {
        fprintf(stderr, "Invalid map file\n");
        return 1;
    }

    void *mlx;           // Ponteiro para a conexão com o sistema gráfico
    void *window;        // Ponteiro para a janela criada
    void *img[4];        // Ponteiro para a imagem
    int img_width;       // Largura da imagem
    int img_height;      // Altura da imagem
    int width = 50 * get_column_number(av[1]);
    int height = 50 * get_line_number(av[1]);

    mlx = mlx_init();
    if (mlx == NULL)
    {
        fprintf(stderr, "Failed to initialize MiniLibX\n");
        return 1;
    }

    window = mlx_new_window(mlx, width, height, "./so_long");
    if (window == NULL)
    {
        fprintf(stderr, "Failed to create window\n");
        return 1;
    }

    for (int i = 0; i < 4; i++)
    {
        img[i] = mlx_xpm_file_to_image(mlx, "img/block49x49.xpm", &img_width, &img_height);
        if (img[i] == NULL)
        {
            fprintf(stderr, "Failed to load image\n");
            return 1;
        }
        mlx_put_image_to_window(mlx, window, img[i], 100 * i, 100 * i);
    }

    mlx_hook(window, 17, 0, close_window, NULL);
    mlx_loop(mlx);

    // Libera a imagem carregada (não será alcançado devido ao exit, mas é uma boa prática)
    for (int i = 0; i < 4; i++)
    {
        if (img[i] != NULL)
            mlx_destroy_image(mlx, img[i]);
    }

    return 0;
}
