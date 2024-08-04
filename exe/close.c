#include <stdlib.h>
#include "../minilibx_mms/mlx.h"
// #include "../minilibx_linux/mlx.h"

typedef struct s_vars
{
    void    *mlx;
    void    *win;
    void    *img;
    int     w;
    int     h;
}           t_vars;

void clean_and_exit(t_vars *vars)
{
    if (vars->img)
    {
        mlx_destroy_image(vars->mlx, vars->img);
    }
    if (vars->win)
    {
        mlx_destroy_window(vars->mlx, vars->win);
    }
    // if (vars->mlx)
    // {
    //     // mlx_destroy_display(vars->mlx);
    //     free(vars->mlx);
    // }
    exit(0);
}

int close(int keycode, t_vars *vars)
{
    if (keycode == 65307) // tecla "esc"
    {
        clean_and_exit(vars);
    }
    return (0);
}

int main(void)
{
    t_vars vars = {0};

    vars.mlx = mlx_init();
    if (!vars.mlx)
        return (1);

    vars.win = mlx_new_window(vars.mlx, 500, 300, "Hello world!");
    if (!vars.win)
    {
        mlx_destroy_display(vars.mlx);
        free(vars.mlx);
        return (1);
    }

    vars.img = mlx_png_file_to_image(vars.mlx, "Attack_2_1.png", &vars.w, &vars.h);
    if (!vars.img)
    {
        mlx_destroy_window(vars.mlx, vars.win);
        mlx_destroy_display(vars.mlx);
        free(vars.mlx);
        return (1);
    }

    mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);

    mlx_hook(vars.win, 2, 1L<<0, close, &vars);
    mlx_loop(vars.mlx);

    // Este ponto não deve ser alcançado devido ao loop infinito
    clean_and_exit(&vars);
}
