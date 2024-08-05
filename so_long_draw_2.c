/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_draw_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:19:56 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/31 10:32:07 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

static int	pos_portal(t_wind *win)
{
	int	r;
	int	l;
	t_point	pos;

	r = 1;
	l = 1;
	pos = find_in_matrix(win->map_matrix, 'E');
	while (win->map_matrix[pos.y][pos.x + r] == '0')
		r++;
	while (win->map_matrix[pos.y][pos.x - l] == '0')
		l++;
	if (l > r)
		return (1);
	else
		return (0);
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
	win->cur_ptl[1] = 0;
	ft_printf("%i", pos_portal(win));
	win->cur_ptl[0] = pos_portal(win);
	// win->ptl[l][c].img_ptr = mlx_xpm_file_to_image(win->mlx, file, &w, &h);
	win->ptl_x = x;
	win->ptl_y = y;
	mlx_put_image_to_window(win->mlx, win->win, win->ptl[0][0].img_ptr, x, y);
}

void	draw_player(t_wind win, int x, int y)
{

}

int update_portal_image(t_wind *win)
{
	int		x;
	int		y;
	void	*img;

	x = win->ptl_x;
	y = win->ptl_y;
	img = win->ptl[win->cur_ptl[0]][win->cur_ptl[1]].img_ptr;

	win->cur_ptl[1] = (win->cur_ptl[1] + 1) % 9;
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
