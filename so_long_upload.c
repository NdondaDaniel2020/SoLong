/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_draw_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:19:56 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/31 10:32:07 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	upload_images1(t_wind *win)
{
	int		w;
	int		h;
	char	*path;

	path = tatame1();
	w = win->block[0].w;
	h = win->block[0].h;
	win->block[0].img_ptr = mlx_xpm_file_to_image(win->mlx, path, &w, &h);
	path = tatame2();
	w = win->block[1].w;
	h = win->block[1].h;
	win->block[1].img_ptr = mlx_xpm_file_to_image(win->mlx, path, &w, &h);
	path = player_back();
	w = win->player[0].w;
	h = win->player[0].h;
	win->player[0].img_ptr = mlx_xpm_file_to_image(win->mlx, path, &w, &h);
	path = player_front();
	w = win->player[0].w;
	h = win->player[0].h;
	win->player[1].img_ptr = mlx_xpm_file_to_image(win->mlx, path, &w, &h);
}

static void	upload_images2(t_wind *win)
{
	int		w;
	int		h;
	char	*path;

	path = star();
	w = win->star.w;
	h = win->star.h;
	win->star.img_ptr = mlx_xpm_file_to_image(win->mlx, path, &w, &h);
	path = empty();
	w = win->bg_img.w;
	h = win->bg_img.h;
	win->bg_img.img_ptr = mlx_xpm_file_to_image(win->mlx, path, &w, &h);
	path = porta_back();
	w = win->ptl[0].w;
	h = win->ptl[0].h;
	win->ptl[0].img_ptr = mlx_xpm_file_to_image(win->mlx, path, &w, &h);
	path = porta_front();
	w = win->ptl[1].w;
	h = win->ptl[1].h;
	win->ptl[1].img_ptr = mlx_xpm_file_to_image(win->mlx, path, &w, &h);
}

void	upload_images(t_wind *win)
{
	upload_images1(win);
	upload_images2(win);
}
