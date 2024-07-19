/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <nmatondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:19:56 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/19 08:51:57 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int 	key_press(int keycode, void *param)
{
    (void)param;
    ft_printf("Tecla: %d\n", keycode);
    if (keycode == 65307) // ESC no Linux
        exit(0);

    return (0);
}

int		close_window(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

char	*read_file(int	fd)
{
	char	*str;
	char	*aux;
	int 	bytes_read;

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
