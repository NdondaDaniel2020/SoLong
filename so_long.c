/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:23:41 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	master(t_wind *win)
{
	win->map_matrix = str_to_matrix(win->map);
	upload_images(win);
	draw_map(win);
	mlx_string_put(win->mlx, win->win, 18, 20, 0xFFFFFF, "Moviment: 0");
	mlx_string_put(win->mlx, win->win, 18, 37, 0xFFFFFF, "Star: 0");
	win->move_count++;
	connection(win);
	mlx_loop(win->mlx);
}

static void	init(t_wind *win)
{
	init_portal(win);
	init_player(win);
	win->frame = 0;
	win->size.w = 0;
	win->size.h = 0;
	win->play_x = 0;
	win->play_y = 0;
	win->is_dead = 0;
	win->time_dead = 0;
	win->move_count = 0;
	win->star_count = 0;
	win->diagonal_x = 0;
	win->diagonal_r = 0;
	win->diagonal_l = 0;
	win->mlx = NULL;
	win->win = NULL;
	win->map = NULL;
	win->move = NULL;
	win->enemy = NULL;
	win->map_matrix = NULL;
	win->star.img_ptr = NULL;
	win->bg_img.img_ptr = NULL;
	win->block[0].img_ptr = NULL;
	win->block[1].img_ptr = NULL;
}

static t_enemy	*add_enimy(void)
{
	int		m;
	int		l;
	int		c;
	t_enemy	*enemy;

	m = 0;
	enemy = (t_enemy *)ft_calloc(1, sizeof(t_enemy));
	if (!enemy)
		return (NULL);
	while (m < 2)
	{
		l = 0;
		while (l < 4)
		{
			c = 0;
			while (c < 6)
			{
				enemy->enemy[m][l][c].img_ptr = NULL;
				c++;
			}
			l++;
		}
		m++;
	}
	return (enemy);
}

static void	ini_enemy(t_enemy **enemy_ptr)
{
	t_enemy	*enemy;

	enemy = *enemy_ptr;
	enemy->move = NULL;
	enemy->frame = 0;
	enemy->enmy_x = 0;
	enemy->enmy_y = 0;
	enemy->is_dead = 0;
	enemy->time_dead = 0;
	enemy->cur_enmy[0] = 0;
	enemy->cur_enmy[1] = 0;
	enemy->cur_enmy[2] = 0;
}

int	main(int ac, char **av)
{
	t_wind	win;

	(void)ac;
	init(&win);
	win.map = get_map(av[1]);
	win.size = size_map(win.map);
	win.enemy = add_enimy();
	ini_enemy(&win.enemy);
	win.size.w *= 50;
	win.size.h *= 50;
	win.mlx = mlx_init();
	if (!win.mlx)
		clean_and_exit(&win);
	win.win = mlx_new_window(win.mlx, win.size.w, win.size.h, "Ninja SoLong");
	if (!win.win)
		clean_and_exit(&win);
	master(&win);
	return (0);
}
