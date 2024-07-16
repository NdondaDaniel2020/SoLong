#include "minilibx-linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>

// Definição da largura e altura da janela
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

// Função de callback para eventos de teclado
int key_press(int keycode, void *param)
{
    (void)param;
    printf("Tecla pressionada: %d\n", keycode);
    if (keycode == 65307) // 65307 é o código para a tecla ESC no Linux
    {
        exit(0);
    }
    return (0);
}

int mouse_hook(int keycode, void *param)
{
    (void)param;
    printf("mouse pressionada: %d\n", keycode);
    if (keycode == 65307) // 65307 é o código para a tecla ESC no Linux
    {
        exit(0);
    }
    return (0);
}

int main()
{
    void *mlx;           // Ponteiro para a conexão com o sistema gráfico
    void *window;        // Ponteiro para a janela criada

    // Inicializa a conexão com o sistema gráfico
    mlx = mlx_init();
    if (mlx == NULL)
    {
        return (1);
    }

    // Cria uma janela com largura, altura e título especificados
    window = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "MiniLibX Window");
    if (window == NULL)
    {
        return (1);
    }

    // Registra a função de callback para eventos de teclado
    mlx_key_hook(window, key_press, NULL);
	mlx_mouse_hook(window, mouse_hook, NULL);

    // Define uma função de saída que será chamada quando a janela for fechada
    mlx_hook(window, 17, 0, close_window, NULL);

    // Entra no loop de eventos, aguardando interações do usuário
    mlx_loop(mlx);

    return (0);
}
