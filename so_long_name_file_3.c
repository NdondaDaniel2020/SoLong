/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_name_file_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:23:41 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/31 12:14:30 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*side_player(int i)
{
	if (i == 0)
		return ("img/Kunoichi-back/");
	return ("img/Kunoichi-front/");
}

char	*jump(void)
{
	return ("Jump_");
}

char	*idle(void)
{
	return ("Idle_");
}

char	*run(void)
{
	return ("Run_");
}
