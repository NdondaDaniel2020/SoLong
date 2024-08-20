/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_update_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:19:56 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	update_portal_image(t_wind *win)
{
	int		x;
	int		y;
	void	*img;

	x = win->ptl_x;
	y = win->ptl_y;
	img = win->ptl[win->cur_ptl[0]][win->cur_ptl[1]].img_ptr;
	win->cur_ptl[1] = (win->cur_ptl[1] + 1) % 9;
	draw_empty(win, x, y);
	mlx_put_image_to_window(win->mlx, win->win, img, x, y);
	usleep(20000);
	return (0);
}
