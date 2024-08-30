/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_enemy_mind_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:19:56 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	make_rounds(t_wind *win, t_point point, int l, int r)
{
	int		size;
	char	direct;

	while ((win->map_matrix[point.y][point.x + r] == '0'))
		r++;
	while ((win->map_matrix[point.y][point.x - l] == '0'))
		l++;
	if (r > l)
		size = r;
	else
		size = l;
	if (r > l)
		direct = '6';
	else
		direct = '4';
	if ((!win->enemy->move) || (win->enemy->move
			&& direct != *(char *)win->enemy->move->content))
	{
		while (size--)
			ft_lstadd_back(&win->enemy->move,
				ft_lstnew((void *)char_lst(direct)));
	}
}

static t_point	enemy_find_to_player(t_wind *win)
{
	int		l;
	int		r;
	t_point	point;

	l = 1;
	r = 1;
	point = find_in_matrix(win->map_matrix, 'A');
	if (point.x == -1 && point.y == -1)
		return ((t_point){-1, -1});
	while ((win->map_matrix[point.y][point.x + r] == '0')
		|| (win->map_matrix[point.y][point.x + r] == 'P'))
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

static void	follow_player(t_wind *win)
{
	t_list	*list;
	t_point	point;

	point = enemy_find_to_player(win);
	if (point.x <= 0 || !win->enemy)
		return ;
	if (*(char *)win->enemy->move->content != point.y + '0')
	{
		clean_command_enemy(&win->enemy->move);
		while (point.x--)
		{
			list = ft_lstnew((void *)char_lst(point.y + '0'));
			if (list != NULL)
				ft_lstadd_back(&win->enemy->move, list);
		}
	}
}

static void	enemy_in_alenta(t_wind *win)
{
	t_list	*list;
	t_point	point;

	point = find_in_matrix(win->map_matrix, 'A');
	if (point.x == -1)
		return ;
	if (win->map_matrix[point.y - 1][point.x - 1] == 'P'
		&& win->map_matrix[point.y][point.x - 1] == '1')
	{
		clean_command_enemy(&win->enemy->move);
		list = ft_lstnew((void *)char_lst('5'));
		if (list != NULL)
			ft_lstadd_back(&win->enemy->move, list);
	}
	if (win->map_matrix[point.y - 1][point.x + 1] == 'P'
		&& win->map_matrix[point.y][point.x + 1] == '1')
	{
		clean_command_enemy(&win->enemy->move);
		list = ft_lstnew((void *)char_lst('5'));
		if (list != NULL)
			ft_lstadd_back(&win->enemy->move, list);
	}
}

void	enemy_mind(t_wind *win)
{
	t_point	point;

	enemy_in_alenta(win);
	follow_player(win);
	if (win->enemy && !win->enemy->move)
	{
		point = find_in_matrix(win->map_matrix, 'A');
		if (point.x == -1 && point.y == -1)
			return ;
		if (find_in_matrix(win->map_matrix, 'P').x != -1)
			make_rounds(win, point, 1, 1);
	}
}
