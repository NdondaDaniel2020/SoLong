/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_draw_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:19:56 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	add_image_to_player(t_wind *win, int m, int l, int c)
{
	int		w;
	int		h;
	char	*value;
	char	*file;
	void	*img;

	value = (char *)ft_calloc(2, sizeof(char));
	value[1] = '\0';
	value[0] = ('1' + c);
	if (l == 0)
		file = ft_strjoin(side_player(m), idle());
	else if (l == 1)
		file = ft_strjoin(side_player(m), run());
	else
		file = ft_strjoin(side_player(m), jump());
	file = ft_strjoin_free(file, value);
	file = ft_strjoin_free(file, format());
	w = win->player[m][l][c].w;
	h = win->player[m][l][c].h;
	img = mlx_xpm_file_to_image(win->mlx, file, &w, &h);
	win->player[m][l][c].img_ptr = img;
	if (!win->player[m][l][c].img_ptr)
		clean_and_exit(win);
	free(value);
	free(file);
}

void	upload_images3(t_wind *win)
{
	int	m;
	int	l;
	int	c;

	m = 0;
	while (m < 2)
	{
		l = 0;
		while (l < 3)
		{
			c = 0;
			while (c < 9)
			{
				add_image_to_player(win, m, l, c);
				c++;
			}
			l++;
		}
		m++;
	}
}