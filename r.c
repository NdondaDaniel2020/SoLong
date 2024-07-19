/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <nmatondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:41:56 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/19 08:49:04 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include <fcntl.h> // Para open
#include <unistd.h> // Para read e close
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    void    *mlx;
    void    *win;
} t_data;

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		l1;
	int		l2;
	int		i;

	if (!s1 && !s2)
		return (NULL);
	i = 0;
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	join = malloc((l1 + l2 + 1) * sizeof(char));
	if (!join)
		return (NULL);
	while (i < (l1 + l2))
	{
		if (i < l1)
			join[i] = s1[i];
		else
			join[i] = s2[i - l1];
		i++;
	}
	join[i] = '\0';
	return (join);
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

int main(void)
{
    t_data  data;

	void *img;           // Ponteiro para a imagem
	int img_width;       // Largura da imagem
    int img_height;      // Altura da imagem

    // Lê o conteúdo de um arquivo
    char *file_content;

	file_content = open_file("map/map1.txt");
	// printf("%s", file_content);
    
	if (file_content == NULL) {
        return 1;
    }

    // Inicializa a conexão com o servidor gráfico
    data.mlx = mlx_init();
    if (data.mlx == NULL) {
        fprintf(stderr, "Erro ao inicializar MiniLibX\n");
        free(file_content);
        return 1;
    }

    // Cria uma janela de 800x600 pixels
    data.win = mlx_new_window(data.mlx, 800, 600, "Exemplo com Arquivo");
    if (data.win == NULL) {
        fprintf(stderr, "Erro ao criar a janela\n");
        free(file_content);
        return 1;
    }

    // Exibe o conteúdo do arquivo na janela
    mlx_string_put(data.mlx, data.win, 50, 50, 0xFFFFFF, file_content);
	
	img = mlx_xpm_file_to_image(data.mlx, "img/terra.xpm", &img_width, &img_height);
	mlx_put_image_to_window(data.mlx, data.win, img, 0, 0);

    mlx_loop(data.mlx);
    free(file_content);
    return 0;
}
