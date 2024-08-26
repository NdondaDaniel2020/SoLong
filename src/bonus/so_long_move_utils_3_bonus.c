/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_move_utils_3_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 08:13:31 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	atack_enemy(t_wind *win)
{
	if (win->enemy->move && *(char *)win->enemy->move->content == '5')
	{
		win->enemy->cur_enmy[1] = 2;
		win->enemy->frame += 5;
		if (win->enemy->frame % 50 == 0)
		{
			lstdel_front(&win->enemy->move);
			win->enemy->cur_enmy[1] = 0;
		}
	}
}

void	death_enemy(t_wind *win)
{
	if (win->enemy->move && *(char *)win->enemy->move->content == '0')
	{
		win->enemy->cur_enmy[1] = 3;
		win->enemy->frame += 5;
		if (win->enemy->frame % 30 == 0)
		{
			lstdel_front(&win->enemy->move);
			win->enemy->is_dead = 1;
			clean_command_enemy(&win->enemy->move);
		}
	}
}
