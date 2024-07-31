/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <nmatondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:19:56 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/19 15:34:57 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_file(int fd)
{
	char	*str;
	char	*aux;
	int		bytes_read;

	bytes_read = 1;
	str = (char *)ft_calloc(1, sizeof(char));
	aux = (char *)ft_calloc(1, sizeof(char) * 2);
	if (!aux || !str)
	{
		free(str);
		free(aux);
		return (NULL);
	}
	while (bytes_read)
	{
		bytes_read = read(fd, aux, 1);
		if (bytes_read == -1)
		{
			free(aux);
			free(str);
			close(fd);
			return (NULL);
		}
		aux[bytes_read] = '\0';
		str = ft_strjoin_free(str, aux);
	}
	close(fd);
	ft_bzero(aux, 1);
	free(aux);
	return (str);
}

char	*open_file(const char *filename)
{
	int		fd;
	char	*str;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	str = read_file(fd);
	return (str);
}
