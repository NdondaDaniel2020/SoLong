/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_kill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 08:13:31 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	kill_player(t_wind *win, t_point point, int x)
{
	int	pos;

	if (point.x == -1)
		return ;
	draw_empty(win, win->play_x, win->play_y);
	pos = 1;
	if (!pos_player(win))
		pos = -1;
	if (win->map_matrix[point.y][point.x + x + x] == '0')
		win->play_x += (30 * pos);
	win->cur_play[0] = !pos_player(win);
	win->map_matrix[point.y][point.x] = '0';
	win->map_matrix[point.y][point.x + x] = 'A';
	win->map_matrix[point.y][point.x + x] = 'A';
	clean_command(win);
	ft_lstadd_back(&win->move,
		ft_lstnew((void *)char_lst('q')));
	ft_lstadd_back(&win->enemy->move,
		ft_lstnew((void *)char_lst('5')));
	ft_lstadd_back(&win->enemy->move,
		ft_lstnew((void *)char_lst('5')));
	ft_lstadd_back(&win->enemy->move,
		ft_lstnew((void *)char_lst('5')));
}

void	kill_enemy(t_wind *win, t_point point)
{
	int	pos;

	if (point.x == -1)
		return ;
	pos = 1;
	if (!pos_enemy(win))
		pos = -1;
	draw_empty(win, win->enemy->enmy_x, win->enemy->enmy_y - 19);
	win->enemy->enmy_x += (30 * pos);
	win->enemy->cur_enmy[0] = !pos_enemy(win);
	win->map_matrix[point.y + 1][point.x] = '0';
	win->map_matrix[point.y + 1][point.x + pos] = 'A';
	win->map_matrix[point.y + 1][point.x + pos] = '0';
	clean_command_enemy(&win->enemy->move);
	ft_lstadd_back(&win->enemy->move,
		ft_lstnew((void *)char_lst('0')));
}
