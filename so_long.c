/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <nmatondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:23:41 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/18 15:09:41 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_read_file(int fd, char *str)
{
	char	*buffer;
	int		rd_bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	rd_bytes = 1;
	while (!ft_find_char_in_point(str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buffer, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[rd_bytes] = '\0';
		str = ft_strjoin_free(str, buffer);
	}
	free(buffer);
	return (str);
}

int	main(int ac, char **av)
{
	void	*mlx;
	void	*win;
	
	int		width = 500;
	int		height = 230;
	
	void *img;           // Ponteiro para a imagem
	int img_width;       // Largura da imagem
    int img_height;      // Altura da imagem
	
	// char *map;

	// map = read_map(av[1]);

	int fd;
	int rd_bytes;
	char *txt;
	
	fd = open(av[1], O_RDONLY);
	
	ft_printf("%s", ft_read_file(fd, txt));

	mlx = mlx_init();
	win = mlx_new_window(mlx, width, height, "./so_long");

	// map = read_map(av[1]);
	// img = mlx_xpm_file_to_image(mlx, "img/terra.xpm", &img_width, &img_height);
	// mlx_put_image_to_window(mlx, win, img, 0, 0);
	
	mlx_key_hook(win, key_press, NULL);
	mlx_hook(win, 17, 0, close_window, NULL);
	
	mlx_loop(mlx);
}