/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_name_file_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:23:41 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/31 12:14:30 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*empty(void)
{
	return ("textures/block/vazio.xpm");
}

char	*player_back(void)
{
	return ("textures/kunoichi-back/idle_1.xpm");
}

char	*player_front(void)
{
	return ("textures/kunoichi-front/idle_1.xpm");
}

char	*side_player(int i)
{
	if (i == 0)
		return ("textures/kunoichi-back/");
	return ("textures/kunoichi-front/");
}

char	*side_portal(int index)
{
	if (index == 0)
		return (porta_back());
	else
		return (porta_front());
}
