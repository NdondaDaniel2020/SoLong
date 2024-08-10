/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_update.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:19:56 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

static void	printf_matrix(t_wind *win)
{
	int	l;
	int	c;
	t_size size;

	l = 0;
	size = size_map(win->map);
	while (l < size.h)
	{
		c = 0;
		while (c < size.w)
		{
			ft_printf("%c", win->map_matrix[l][c]);
			c++;
		}
		ft_printf("\n");
		l++;
	}
}

static int	update_player_image(t_wind *win)
{
	// int		x;
	// int		y;
	int		cur[3];
	void	*img;
	t_point	point;

	t_list	*list;


	point = find_in_matrix(win->map_matrix, 'P');
	ft_printf("%i %i\n", point.y, point.x);
	printf_matrix(win);


	cur[0] = win->cur_play[0];
	cur[1] = win->cur_play[1];
	cur[2] = win->cur_play[2];
	img = win->player[cur[0]][cur[1]][cur[2]].img_ptr;
	if (img == NULL)
		clean_and_exit(win);
	win->cur_play[2] = (win->cur_play[2] + 1) % 9;

	draw_empty(win, win->play_x, win->play_y);

	if (win->map_matrix[point.y + 1][point.x] == '0')
	{
		list = ft_lstnew((void *)char_lst('s'));
		ft_lstadd_back(&win->move, list);
	}

	ft_printf("   {%c}\n", win->map_matrix[point.y - 1][point.x]);
	ft_printf("{%c}", win->map_matrix[point.y][point.x - 1]);
	ft_printf("{%c}", win->map_matrix[point.y][point.x]);
	ft_printf("{%c}\n", win->map_matrix[point.y][point.x + 1]);
	ft_printf("   {%c}\n", win->map_matrix[point.y + 1][point.x]);

	if (win->move)
	{
		lstls(win->move);
		if (*(char *)win->move->content == 'd'&& win->map_matrix[point.y][point.x + 1] == '0')
		{
			win->cur_play[0] = 1;
			win->cur_play[1] = 1;
			win->play_x += 5;
			if (win->play_x % 50 == 0)
			{
				lstdel_front(&win->move);
				win->map_matrix[point.y][point.x] = '0';
				win->map_matrix[point.y][point.x + 1] = 'P';
				win->cur_play[1] = 0;
			}
		}
		else if (*(char *)win->move->content == 'a' && win->map_matrix[point.y][point.x - 1] == '0')
		{
			win->cur_play[0] = 0;
			win->cur_play[1] = 1;
			win->play_x -= 5;
			if (win->play_x % 50 == 0)
			{
				lstdel_front(&win->move);
				win->map_matrix[point.y][point.x] = '0';
				win->map_matrix[point.y][point.x - 1] = 'P';
				win->cur_play[1] = 0;
			}
		}
		else if (*(char *)win->move->content == 'w' && win->map_matrix[point.y - 1][point.x] == '0')
		{
			win->cur_play[1] = 2;
			win->play_y -= 5;
			if (win->play_y % 50 == 0)
			{
				lstdel_front(&win->move);
				win->map_matrix[point.y][point.x] = '0';
				win->map_matrix[point.y - 1][point.x] = 'P';
				win->cur_play[1] = 0;
			}
		}
		else if (*(char *)win->move->content == 's')
		{
			win->cur_play[1] = 0;
			if (win->map_matrix[point.y + 1][point.x] == '0')
			{
				win->play_y += 5;
				if (win->play_y % 50 == 0)
				{
					win->map_matrix[point.y][point.x] = '0';
					win->map_matrix[point.y + 1][point.x] = 'P';
				}
			}
			lstdel_front(&win->move);
		}
		else
			lstdel_front(&win->move);
	}
	// system("clear");
	mlx_put_image_to_window(win->mlx, win->win, img, win->play_x, win->play_y);
	usleep(40000);
	return (0);
}

static int	update_portal_image(t_wind *win)
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

int	update_image(t_wind *win)
{
	update_portal_image(win);
	update_player_image(win);
	return (0);
}
