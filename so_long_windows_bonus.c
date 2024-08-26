/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_wind_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:19:56 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*window*/
int	key_press(int keycode, t_wind *win)
{
	t_list	*list;

	if (keycode == 65307)
		clean_and_exit(win);
	if (keycode == 65363)
	{
		list = ft_lstnew((void *)char_lst('d'));
		ft_lstadd_back(&win->move, list);
	}
	if (keycode == 65361)
	{
		list = ft_lstnew((void *)char_lst('a'));
		ft_lstadd_back(&win->move, list);
	}
	if (keycode == 65362)
	{
		list = ft_lstnew((void *)char_lst('w'));
		ft_lstadd_back(&win->move, list);
	}
	return (0);
}

int	clean_and_exit(t_wind *win)
{
	clean(win);
	if (win->map_matrix)
		free_matrix(win->map_matrix);
	if (win->map)
		free(win->map);
	if (win->bg_img.img_ptr)
		mlx_destroy_image(win->mlx, win->bg_img.img_ptr);
	if (win->win)
		mlx_destroy_window(win->mlx, win->win);
	if (win->mlx)
	{
		mlx_destroy_display(win->mlx);
		free(win->mlx);
	}
	exit(0);
}

int	clean(t_wind *win)
{
	if (win->star.img_ptr)
		mlx_destroy_image(win->mlx, win->star.img_ptr);
	if (win->block[0].img_ptr)
		mlx_destroy_image(win->mlx, win->block[0].img_ptr);
	if (win->block[1].img_ptr)
		mlx_destroy_image(win->mlx, win->block[1].img_ptr);
	if (win->ptl[0][0].img_ptr)
		clean_portal(win);
	if (win->player[0][0][0].img_ptr)
		clean_player(win);
	if (win->move)
		clean_command(win);
	if (win->enemy && win->enemy->move)
		clean_command_enemy(&win->enemy->move);
	if (win->enemy && win->enemy->enemy[0][0][0].img_ptr)
		clean_enemy(win);
	return (0);
}

void	connection(t_wind *win)
{
	mlx_key_hook(win->win, key_press, win);
	mlx_hook(win->win, 17, 0, clean_and_exit, win);
	mlx_loop_hook(win->mlx, (int (*)())update_image, win);
}
