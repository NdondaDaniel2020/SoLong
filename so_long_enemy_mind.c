/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_enemy_mind.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:19:56 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void make_rounds(t_wind *win, t_point point)
{
	int	l;
	int	r;

	l = 1;
	r = 1;
	while ((win->map_matrix[point.y][point.x + r] == '0'))
		r++;
	while ((win->map_matrix[point.y][point.x - l] == '0'))
		l++;
	if (r > l)
	{
		while (r--)
		{
			ft_lstadd_back(&win->enemy->move, 
				ft_lstnew((void *)char_lst('6')));
		}
	}
	else
	{
		while (l--)
		{
			ft_lstadd_back(&win->enemy->move, 
				ft_lstnew((void *)char_lst('4')));
		}
	}
}

static t_point enemy_find_to_player(t_wind *win)
{
	int		l;
	int		r;
	t_point point;

	l = 1;
	r = 1;
	point = find_in_matrix(win->map_matrix, 'A');
	if (point.x == -1 && point.y == -1)
		return ((t_point){-1, -1});
	while ((win->map_matrix[point.y][point.x + r] == '0') || 
		(win->map_matrix[point.y][point.x + r] == 'P'))
	{
		if (win->map_matrix[point.y][point.x + r] == 'P')
			return ((t_point){r, 6});
		r++;
	}
	while ((win->map_matrix[point.y][point.x - l] == '0') ||
		(win->map_matrix[point.y][point.x - l] == 'P'))
	{
		if (win->map_matrix[point.y][point.x - l] == 'P')
			return ((t_point){l, 4});
		l++;
	}
	return ((t_point){-1, -1});
}

static void follow_player(t_wind *win, t_point point)
{
	if (point.x == -1)
		return ;
	clean_command_enemy(&win->enemy->move);
	while (point.x--)
	{
		ft_lstadd_back(&win->enemy->move, 
			ft_lstnew((void *)ft_itoa(point.y)));
	}
}

static void	enemy_in_alenta(t_wind *win)
{
	t_point	point;

	point = find_in_matrix(win->map_matrix, 'A');
	if (point.x == -1)
		return ;
	if (win->map_matrix[point.y - 1][point.x - 1] == 'P')
	{
        clean_command_enemy(&win->enemy->move);
		ft_lstadd_back(&win->enemy->move,
			ft_lstnew((void *)char_lst('5')));
	}
	if (win->map_matrix[point.y - 1][point.x + 1] == 'P')
	{
        clean_command_enemy(&win->enemy->move);
		ft_lstadd_back(&win->enemy->move,
			ft_lstnew((void *)char_lst('5')));
	}
}

void	enemy_mind(t_wind *win)
{
	t_point point;

	follow_player(win, enemy_find_to_player(win));
	enemy_in_alenta(win);
	if (!win->enemy->move)
	{
		point = find_in_matrix(win->map_matrix, 'A');
		if (point.x == -1 && point.y == -1)
			return ;
		make_rounds(win, point);
	}
}
