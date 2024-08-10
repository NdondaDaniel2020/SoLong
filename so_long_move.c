/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 08:13:31 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


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

static int      condition_move(t_wind *win, int x, int y)
{
        int             c;
        t_point point;

		c = count_occurrence(win->map_matrix, 'C');
        point = find_in_matrix(win->map_matrix, 'P');

		ft_printf("   {%c}\n", win->map_matrix[point.y - 1][point.x]);
		ft_printf("{%c}", win->map_matrix[point.y][point.x - 1]);
		ft_printf("{%c}", win->map_matrix[point.y][point.x]);
		ft_printf("{%c}\n", win->map_matrix[point.y][point.x + 1]);
		ft_printf("   {%c}\n", win->map_matrix[point.y + 1][point.x]);
		
		lstls(win->move);

		printf_matrix(win);

        if (win->map_matrix[point.y + y][point.x + x] == '0')
                return (1);
        if (win->map_matrix[point.y + y][point.x + x] == 'C')
                return (1);
        if (win->map_matrix[point.y + y][point.x + x] == 'E' && c == 0)
                clean_and_exit(win);
        return (0);
}

static void	move_up(t_wind *win)
{
	t_point	point;

	if (win->move && *(char *)win->move->content == 'w')
	{
		if (condition_move(win, 0, -1))
		{
			win->cur_play[1] = 2;
			win->play_y -= 5;
			if (win->play_y % 50 == 0)
			{
				point = find_in_matrix(win->map_matrix, 'P');
				win->map_matrix[point.y][point.x] = '0';
				win->map_matrix[point.y - 1][point.x] = 'P';
				win->cur_play[1] = 0;
				lstdel_front(&win->move);
			}
		}
		else
			lstdel_front(&win->move);
	}
}

static void	move_down(t_wind *win)
{
	t_point	point;

	if (win->move && *(char *)win->move->content == 's')
	{
		if (condition_move(win, 0, 1))
		{
			win->cur_play[1] = 0;
			win->play_y += 5;
			if (win->play_y % 50 == 0)
			{
				point = find_in_matrix(win->map_matrix, 'P');
				win->map_matrix[point.y][point.x] = '0';
				win->map_matrix[point.y + 1][point.x] = 'P';
				lstdel_front(&win->move);
			}
		}
		else
			lstdel_front(&win->move);
	}
}

static void	move_right(t_wind *win)
{
	t_point	point;

	if (win->move && *(char *)win->move->content == 'd')
	{
		if (condition_move(win, 1, 0))
		{
			win->cur_play[0] = 1;
			win->cur_play[1] = 1;
			win->play_x += 5;
			if (win->play_x % 50 == 0)
			{
				point = find_in_matrix(win->map_matrix, 'P');
				win->map_matrix[point.y][point.x] = '0';
				win->map_matrix[point.y][point.x + 1] = 'P';
				win->cur_play[1] = 0;
				lstdel_front(&win->move);
			}
		}
		else
			lstdel_front(&win->move);
	}
}

static void	move_left(t_wind *win)
{
	t_point point;

	if (win->move && *(char *)win->move->content == 'a')
	{
		if (condition_move(win, -1, 0))
		{
			win->cur_play[0] = 0;
			win->cur_play[1] = 1;
			win->play_x -= 5;
			if (win->play_x % 50 == 0)
			{
				point = find_in_matrix(win->map_matrix, 'P');
				win->map_matrix[point.y][point.x] = '0';
				win->map_matrix[point.y][point.x - 1] = 'P';
				win->cur_play[1] = 0;
				lstdel_front(&win->move);
			}
		}
		else
			lstdel_front(&win->move);
	}
}

void	move_player(t_wind *win)
{
	lstls(win->move);
	move_up(win);
	move_down(win);
	move_right(win);
	move_left(win);
}
