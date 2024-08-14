/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_update_score.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:19:56 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_move_count(t_wind *win)
{
	void	*img;
	char	*value;
	char	*v_aux;
	char	*star;
	char	*movement;

	img = win->block[1].img_ptr;
	value = ft_itoa(win->move_count);
	v_aux = ft_itoa(win->star_count);
	star = ft_strjoin("Star: ", v_aux);
	movement = ft_strjoin("Moviment: ", value);
	mlx_put_image_to_window(win->mlx, win->win, img, 0, 0);
	mlx_put_image_to_window(win->mlx, win->win, img, 50, 0);
	mlx_string_put(win->mlx, win->win, 18, 37, 0xFFFFFF, star);
	mlx_string_put(win->mlx, win->win, 18, 20, 0xFFFFFF, movement);
	win->move_count++;
	free(movement);
	free(value);
	free(v_aux);
	free(star);
}

void	update_star_count(t_wind *win)
{
	void	*img;
	char	*value;
	char	*v_aux;
	char	*star;
	char	*movement;

	img = win->block[1].img_ptr;
	value = ft_itoa(win->star_count);
	v_aux = ft_itoa(win->move_count);
	star = ft_strjoin("Star: ", value);
	movement = ft_strjoin("Moviment: ", v_aux);
	mlx_put_image_to_window(win->mlx, win->win, img, 0, 0);
	mlx_put_image_to_window(win->mlx, win->win, img, 50, 0);
	mlx_string_put(win->mlx, win->win, 18, 37, 0xFFFFFF, star);
	mlx_string_put(win->mlx, win->win, 18, 20, 0xFFFFFF, movement);
	win->star_count++;
	free(movement);
	free(v_aux);
	free(value);
	free(star);
}
