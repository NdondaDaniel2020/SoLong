/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <nmatondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:19:56 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/18 14:51:42 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_press(int keycode, void *param)
{
    (void)param;
    ft_printf("Tecla: %d\n", keycode);
    if (keycode == 65307) // ESC no Linux
        exit(0);

    return (0);
}

int	close_window(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

// char *read_map(char *file)
// {
// 	int		fd;
// 	char	*inf;
// 	char	*aux;

// 	inf = (char *)malloc(sizeof(char) * 1);
// 	inf[0] = '\0';
// 	fd = open(file, O_RDONLY);
// 	aux = get_next_line(fd);
// 	while (aux)
// 	{
// 		inf = ft_strjoin_free(inf, aux);
// 		aux = get_next_line(fd);
// 	}
// 	free(aux);
// 	close(fd);
// 	return (inf);
// }