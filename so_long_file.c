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
	str = (char *)malloc(sizeof(char));
	str[0] = '\0';
	aux = (char *)malloc(sizeof(char) * 1);
	if (!aux)
		return (NULL);
	while (bytes_read)
	{
		bytes_read = read(fd, aux, 1);
		if (bytes_read == -1)
		{
			free(aux);
			close(fd);
			return (NULL);
		}
		aux[bytes_read] = '\0';
		str = ft_strjoin(str, aux);
	}
	close(fd);
	return (str);
}

char	*open_file(const char *filename)
{
	int		fd;
	char	*str;

	str = NULL;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	str = read_file(fd);
	return (str);
}
