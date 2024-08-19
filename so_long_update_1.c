/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_update_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:19:56 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	update_enemy(t_wind *win)
{
	int		cur[3];
	void	*img;
	t_list	*list;
	t_point	point;

	point = find_in_matrix(win->map_matrix, 'A');
	if (point.x == -1)
		return ;
	if ((!win->enemy->move) || (win->enemy->move
			&& *(char *)win->enemy->move->content != '2'
			&& win->map_matrix[point.y + 1][point.x] == '0'))
	{
		list = ft_lstnew((void *)char_lst('2'));
		ft_lstadd_back(&win->enemy->move, list);
	}
	cur[0] = win->enemy->cur_enmy[0];
	cur[1] = win->enemy->cur_enmy[1];
	cur[2] = win->enemy->cur_enmy[2];
	img = win->enemy->enemy[cur[0]][cur[1]][cur[2]].img_ptr;
	if (!img)
		clean_and_exit(win);
	win->enemy->cur_enmy[2] = (win->enemy->cur_enmy[2] + 1) % 6;
	draw_empty(win, win->enemy->enmy_x, win->enemy->enmy_y - 19);
	move_enemy(win);
	mlx_put_image_to_window(win->mlx, win->win, img,
		win->enemy->enmy_x, win->enemy->enmy_y);
}

static int	update_enemy_image(t_wind *win)
{
	if (win->enemy->is_dead)
	{
		win->enemy->time_dead++;
		if (win->enemy->time_dead < 5)
			draw_empty(win, win->enemy->enmy_x, win->enemy->enmy_y - 19);
		lstdel_front(&win->enemy->move);
	}
	else
		update_enemy(win);
	usleep(10000);
	return (0);
}

static void	update_player(t_wind *win)
{
	int		cur[3];
	void	*img;
	t_list	*list;
	t_point	point;

	point = find_in_matrix(win->map_matrix, 'P');
	if (point.x == -1)
		return ;
	if ((!win->move) || (win->move && *(char *)win->move->content != 's'
			&& win->map_matrix[point.y + 1][point.x] == '0'))
	{
		list = ft_lstnew((void *)char_lst('s'));
		ft_lstadd_back(&win->move, list);
	}
	cur[0] = win->cur_play[0];
	cur[1] = win->cur_play[1];
	cur[2] = win->cur_play[2];
	img = win->player[cur[0]][cur[1]][cur[2]].img_ptr;
	if (!img)
		clean_and_exit(win);
	win->cur_play[2] = (win->cur_play[2] + 1) % 9;
	draw_empty(win, win->play_x, win->play_y);
	move_player(win);
	mlx_put_image_to_window(win->mlx, win->win, img, win->play_x, win->play_y);
}

static int	update_player_image(t_wind *win)
{
	if (win->is_dead)
	{
		win->time_dead++;
		if (win->time_dead < 5)
			draw_empty(win, win->play_x, win->play_y);
		if (win->time_dead == 40)
		{
			clean_and_exit(win);
			return (0);
		}
		lstdel_front(&win->move);
	}
	else
		update_player(win);
	usleep(40000);
	return (0);
}

int	update_image(t_wind *win)
{
	// enemy_mind(win);
	update_portal_image(win);
	update_player_image(win);
	update_enemy_image(win);
	return (0);
}
