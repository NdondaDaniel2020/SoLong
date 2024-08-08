/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_draw_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:19:56 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


static void	add_image_to_player(t_wind *win, int m, int l, int c)
{
	int		w;
	int		h;
	char	*value;
	char	*file;
	void	*img;

	value = (char *)ft_calloc(2, sizeof(char));
	value[1] = '\0';
	value[0] = ('1' + c);
	if (l == 0)
		file = ft_strjoin(side_player(m), idle());
	else if (l == 1)
		file = ft_strjoin(side_player(m), run());
	else
		file = ft_strjoin(side_player(m), jump());
	file = ft_strjoin_free(file, value);
	file = ft_strjoin_free(file, format());
	w = win->player[m][l][c].w;
	h = win->player[m][l][c].h;
	img = mlx_xpm_file_to_image(win->mlx, file, &w, &h);
	win->player[m][l][c].img_ptr = img;
	free(value);
}

static void	upload_images3(t_wind *win)
{
	int	m;
	int	l;
	int	c;

	m = 0;
	while (m < 2)
	{
		l = 0;
		while (l < 3)
		{
			c = 0;
			while (c < 9)
			{
				add_image_to_player(win, m, l, c);
				c++;
			}
			l++;
		}
		m++;
	}
}

static void	add_image_to_portal(t_wind *win, int l, int c)
{
	int		w;
	int		h;
	char	*file;
	char	*num;

	num = (char *)ft_calloc(2, sizeof(char));
	num[1] = '\0';
	num[0] = ('1' + c);
	file = ft_strjoin(side_portal(l), (const char *)num);
	file = ft_strjoin_free(file, format());
	w = win->ptl[l][c].w;
	h = win->ptl[l][c].h;
	win->ptl[l][c].img_ptr = mlx_xpm_file_to_image(win->mlx, file, &w, &h);
	if (!win->ptl[l][c].img_ptr)
		clean_and_exit(win);
	free(file);
	free(num);
}

static void	upload_images2(t_wind *win)
{
	int		l;
	int		c;
	
	l = 0;
	while (l < 2)
	{
		c = 0;
		while (c < 9)
		{
			add_image_to_portal(win, l, c);
			c++;
		}
		l++;
	}
}

static void	upload_images1(t_wind *win)
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
	path = tatame1();
	w = win->block[0].w;
	h = win->block[0].h;
	win->block[0].img_ptr = mlx_xpm_file_to_image(win->mlx, path, &w, &h);
	path = tatame2();
	w = win->block[1].w;
	h = win->block[1].h;
	win->block[1].img_ptr = mlx_xpm_file_to_image(win->mlx, path, &w, &h);
}

void	upload_images(t_wind *win)
{
	upload_images1(win);
	upload_images2(win);
	upload_images3(win);
}

void	clean_portal(t_wind *win)
{
	int	l;
	int	c;

	l = 0;
	while (l < 2)
	{
		c = 0;
		while (c < 9)
		{
			win->ptl[l][c].h = 0;
			win->ptl[l][c].w = 0;
			mlx_destroy_image(win->mlx, win->ptl[l][c].img_ptr);
			c++;
		}
		l++;
	}
}

void	clean_player(t_wind *win)
{
	int	m;
	int	l;
	int	c;

	m = 0;
	while (m < 2)
	{
		l = 0;
		while (l < 3)
		{
			c = 0;
			while (c < 9)
			{
				mlx_destroy_image(win->mlx, win->player[m][l][c].img_ptr);
				c++;
			}
			l++;
		}
		m++;
	}
}
