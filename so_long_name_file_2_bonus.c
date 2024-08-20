/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_name_file_2_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 08:13:31 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*empty(void)
{
	return ("textures/block/vazio.xpm");
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
		return ("textures/portal-back/portal_");
	return ("textures/portal-front/portal_");
}

char	*side_enemy(int index)
{
	if (index == 0)
		return ("textures/enemy-back/");
	return ("textures/enemy-front/");
}
