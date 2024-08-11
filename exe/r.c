#include "../minilibx-linux/mlx.h"

int main()
{
    void *mlx;
    void *win;

    // Inicializando MiniLibX
    mlx = mlx_init();
    win = mlx_new_window(mlx, 800, 600, "Texto na Tela");

    // Escrevendo texto na tela
    mlx_string_put(mlx, win, 100, 100, 0xFFFFFF, "Olá, Mundo!");

    // Iniciando o loop de eventos
    mlx_loop(mlx);

    return 0;
}
