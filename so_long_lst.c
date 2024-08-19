/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:23:41 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	lstdel_front(t_list **list)
{
	t_list	*removed;

	if (*list)
	{
		removed = *list;
		*list = removed->next;
		free(removed->content);
		free(removed);
		removed = NULL;
	}
}

char	*char_lst(char ch)
{
	char	*cha;

	cha = (char *)ft_calloc(2, sizeof(char));
	if (!cha)
		return (NULL);
	cha[0] = ch;
	cha[1] = '\0';
	return (cha);
}
