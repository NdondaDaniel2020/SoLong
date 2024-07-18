/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <nmatondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:41:56 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/18 13:14:42 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char *read_map(char *file)
{
	int		fd;
	char	*inf;
	char	*aux;

	ft_initstr(&inf);
	fd = open(file, O_RDONLY);
	aux = get_next_line(fd);
	while (aux)
	{
		inf = ft_strjoin_free(inf, aux);
		aux = get_next_line(fd);
	}
	free(aux);
	close(fd);
	return (inf);
}

int main(void)
{
	ft_printf("%s\n", read_map("map/map1.txt"));
}