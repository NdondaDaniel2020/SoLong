/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_draw_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:19:56 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/31 10:32:07 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*join_path(int m, int l, int c)
{
	char	*value;
	char	*file;

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
	free(value);
	return (file);
}

static void	add_image_to_player(t_wind *win, int m)
{
	int		l;
	int		c;
	t_image	ply;
	char	*path;

	l = 0;
	while (l < 3)
	{
		c = 0;
		while (c < 9)
		{
			path = join_path(m, l, c);
			ply.img_ptr = mlx_xpm_file_to_image(win->mlx, path, &ply.w, &ply.h);
			if (!ply.img_ptr)
			{
				ft_printf("erro de carregamento da imagem do player\n%s\n", path);
				clean_and_exit(win);
			}
			win->player[m][l][c] = ply;
			free(path);
			c++;
		}
		l++;
	}
}

static int	pos_player(t_wind *win)
{
	int		r;
	int		l;
	t_point	pos;

	r = 1;
	l = 1;
	pos = find_in_matrix(win->map_matrix, 'P');
	while (win->map_matrix[pos.y][pos.x + r] == '0')
		r++;
	while (win->map_matrix[pos.y][pos.x - l] == '0')
		l++;
	if (l > r)
		return (0);
	else
		return (1);
}

void	draw_player(t_wind *win, int x, int y)
{
	int		m;
	int		pos;
	t_image	img;

	m = 0;
	while (m < 2)
	{
		add_image_to_player(win, m);
		m++;
	}
	win->play_x = x;
	win->play_y = y-3;
	pos = pos_player(win);
	win->cur_play[0] = pos;
	win->cur_play[1] = 0;
	win->cur_play[2] = 0;
	img = win->player[pos][0][0];
	mlx_put_image_to_window(win->mlx, win->win, img.img_ptr, x, y-3);
}

int	update_player_image(t_wind *win)
{
	int		x;
	int		y;
	int		cur[3];
	void	*img;

	(void)win;
	x = win->play_x;
	y = win->play_y;
	cur[0] = win->cur_play[0];
	cur[1] = win->cur_play[1];
	cur[2] = win->cur_play[2];
	img = win->player[cur[0]][cur[1]][cur[2]].img_ptr;
	if (img == NULL)
		clean_and_exit(win);
	win->cur_play[2] = (win->cur_play[2] + 1) % 9;
	mlx_put_image_to_window(win->mlx, win->win, img, x, y);
	usleep(90000);
	return (0);
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
