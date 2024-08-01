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

char	*read_file(int fd, char *str, char *buffer)
{
	int		bytes_read;

	bytes_read = 1;
	while (bytes_read)
	{
		bytes_read = read(fd, buffer, 1);
		if (bytes_read == -1)
		{
			free(buffer);
			free(str);
			close(fd);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		str = ft_strjoin_free(str, buffer);
	}
	close(fd);
	ft_bzero(buffer, 1);
	free(buffer);
	return (str);
}

char	*open_file(const char *filename)
{
	int		fd;
	char	*str;
	char	*buffer;

	fd = open(filename, O_RDONLY);
	str = (char *)ft_calloc(1, sizeof(char));
	buffer = (char *)ft_calloc(1, sizeof(char) * 2);
	if (fd == -1 || !str || !buffer)
	{
		free(str);
		free(buffer);
		return (NULL);
	}
	str = read_file(fd, str, buffer);
	return (str);
}
