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
	}
}

void	lstls(t_list *list)
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

char	*char_lst(char ch)
{
	char	*c = malloc(2*sizeof(char));

	c[1] = '\0';
	c[0] = ch;
	return (c);
}
