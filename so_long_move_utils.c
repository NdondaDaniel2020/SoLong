/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_move_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 08:13:31 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	lstls(t_list *list)
{
	int	i;

	i = 0;
	if (list)
	{
		ft_printf("Lista\n");
		while (list)
		{
			ft_printf("%i - %c\n", i, *(char *)list->content);
			list = list->next;
			i++;
		}
		ft_printf("\n");
	}
}

int	condition_move(t_wind *win, int x, int y)
{
	int			c;
	t_point		point;
	static int	aux = 0;

	c = count_occurrence(win->map_matrix, 'C');
	point = find_in_matrix(win->map_matrix, 'P');
	
	lstls(win->move);
	
	ft_printf("{%c}", win->map_matrix[point.y - 1][point.x - 1]);
	ft_printf("{%c}", win->map_matrix[point.y - 1][point.x]);
	ft_printf("{%c}\n", win->map_matrix[point.y - 1][point.x + 1]);

	ft_printf("{%c}", win->map_matrix[point.y][point.x - 1]);
	ft_printf("{%c}", win->map_matrix[point.y][point.x]);
	ft_printf("{%c}\n", win->map_matrix[point.y][point.x + 1]);

	ft_printf("{%c}", win->map_matrix[point.y + 1][point.x - 1]);
	ft_printf("{%c}", win->map_matrix[point.y + 1][point.x]);
	ft_printf("{%c}\n\n", win->map_matrix[point.y + 1][point.x + 1]);
	
	ft_printf("[%i]\n", win->play_x);

	if (win->map_matrix[point.y + y][point.x + x] == '0')
		return (1);
	if (win->map_matrix[point.y + y][point.x + x] == 'C')
		return (1);
	if (win->map_matrix[point.y + y][point.x + x] == 'E' && c == 0)
	{
		aux++;
		if (aux == 5)
			clean_and_exit(win);
		return (1);
	}
	return (0);
}

int	condition_move_top_right(t_wind *win, t_point point)
{
	if ((win->map_matrix[point.y - 1][point.x] == '0' || win->map_matrix[point.y - 1][point.x] == 'C')
		&& (win->map_matrix[point.y - 1][point.x + 1] == '0' || win->map_matrix[point.y - 1][point.x + 1] == 'C')
		&& (win->map_matrix[point.y][point.x + 1] == '0' || win->map_matrix[point.y][point.x + 1] == 'C')
	)
		win->diagonal_r = 1;
	return (0);
}

void	get_star(t_wind *win, int x, int y)
{
	t_point	point;

	point = find_in_matrix(win->map_matrix, 'P');
	if (win->map_matrix[point.y + y][point.x + x] == 'C')
		update_star_count(win);
}

int	movement_blocked_right(t_wind *win)
{
	t_point	point;

	point = find_in_matrix(win->map_matrix, 'P');
	if ((win->map_matrix[point.y][point.x + 1] == '0'
		|| win->map_matrix[point.y][point.x + 1] == 'C')
		&& (win->map_matrix[point.y + 1][point.x] == '0'
		|| win->map_matrix[point.y + 1][point.x] == 'C')
		&& (win->map_matrix[point.y + 1][point.x + 1] == '0'
		|| win->map_matrix[point.y + 1][point.x + 1] == 'C'))
	{
		lstdel_front(&win->move);
		return (1);
	}
	return (0);
}

int	movement_blocked_left(t_wind *win)
{
	t_point	point;

	point = find_in_matrix(win->map_matrix, 'P');
	if ((win->map_matrix[point.y][point.x - 1] == '0'
		|| win->map_matrix[point.y][point.x - 1] == 'C')
		&& (win->map_matrix[point.y + 1][point.x - 1] == '0'
		|| win->map_matrix[point.y + 1][point.x - 1] == 'C')
		&& (win->map_matrix[point.y + 1][point.x] == '0'
		|| win->map_matrix[point.y + 1][point.x] == 'C'))
	{
		lstdel_front(&win->move);
		return (1);
	}
	return (0);
}
