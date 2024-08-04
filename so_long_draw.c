/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:19:56 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/31 10:32:07 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_wind *win)
{
	int		l;
	int		y;
	int		i;
	int		len;

	l = 0;
	y = 0;
	i = 0;
	len = count_occurrence(win->map_matrix, '1');
	len += count_occurrence(win->map_matrix, 'C');
	win->imgs = (t_image *)ft_calloc(len, sizeof(t_image));
	if (!win->imgs)
		clean_and_exit(win);
	while (win->map_matrix[l])
	{
		draw_line_map(win, l, y, &i);
		y += 50;
		l++;
	}
}

void	draw_line_map(t_wind *win, int l, int y, int *i)
{
	int		c;
	int		x;

	c = 0;
	x = 0;
	while (win->map_matrix[l][c])
	{
		if (win->map_matrix[l][c] == '1')
		{
			if (is_border(win, l, c))
				draw_tatami_2(win, x, y, i);
			else
				draw_tatami_1(win, x, y, i);
		}
		if (win->map_matrix[l][c] == 'C')
			draw_star(win, x, y, i);
		if (win->map_matrix[l][c] == 'E')
			draw_portal(win, x, y);
		// if (win->map_matrix[l][c] == 'P')
		x += 50;
		c++;
	}
}

void	draw_star(t_wind *win, int x, int y, int *i)
{
	int	w;
	int	h;

	x += 10;
	y += 10;
	w = win->imgs[*i].w;
	h = win->imgs[*i].h;
	win->imgs[*i].img_ptr = mlx_xpm_file_to_image(win->mlx, star(), &w, &h);
	if (!win->imgs)
		clean_and_exit(win);
	mlx_put_image_to_window(win->mlx, win->win, win->imgs[*i].img_ptr, x, y);
	(*i)++;
}

void	draw_tatami_1(t_wind *win, int x, int y, int *i)
{
	int	w;
	int	h;

	w = win->imgs[*i].w;
	h = win->imgs[*i].h;
	win->imgs[*i].img_ptr = mlx_xpm_file_to_image(win->mlx, tatame1(), &w, &h);
	if (!win->imgs)
		clean_and_exit(win);
	mlx_put_image_to_window(win->mlx, win->win, win->imgs[*i].img_ptr, x, y);
	(*i)++;
}

void	draw_tatami_2(t_wind *win, int x, int y, int *i)
{
	int	w;
	int	h;

	w = win->imgs[*i].w;
	h = win->imgs[*i].h;
	win->imgs[*i].img_ptr = mlx_xpm_file_to_image(win->mlx, tatame2(), &w, &h);
	if (!win->imgs)
		clean_and_exit(win);
	mlx_put_image_to_window(win->mlx, win->win, win->imgs[*i].img_ptr, x, y);
	(*i)++;
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

void	draw_portal(t_wind *win, int x, int y)
{
	int		l;
	int		c;

	(void)x;
	(void)y;
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
	win->cur_ptl = 0;
	// win->ptl[l][c].img_ptr = mlx_xpm_file_to_image(win->mlx, file, &w, &h);
	win->ptl_x = x;
	win->ptl_y = y;
	mlx_put_image_to_window(win->mlx, win->win, win->ptl[0][0].img_ptr, x, y);
}

int update_portal_image(t_wind *win)
{
	int		x;
	int		y;
	void	*img;

	x = win->ptl_x;
	y = win->ptl_y;
	img = win->ptl[0][win->cur_ptl].img_ptr;

	win->cur_ptl = (win->cur_ptl + 1) % 9;
	// mlx_clear_window(win->mlx, win->win);
	// mlx_destroy_image(win->mlx, win->ptl[0][win->cur_ptl].img_ptr);
    mlx_put_image_to_window(win->mlx, win->win, img, x, y);
	usleep(100000);
    return (0);
}

void 	clean_portal(t_wind *win)
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
