/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <nmatondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:17:04 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/19 15:33:55 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx_mms/mlx.h"
# include "minilibx_linux/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>

typedef struct s_size
{
	int	width;
	int	height;
}		t_size;

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

typedef struct s_
{
	void	*mlx;
	void	*win;
}			t_data;

/*window*/
int		key_press(int keycode, void *param);
int		close_window(void *param);

/*file*/
char	*read_file(int fd);
char	*open_file(const char *filename);

/*check map*/
int		check_line(char *map_line, int *column);
int		check_struct_map(char *map);
int		check_duplicate(char *map);
int		check_map(char *map);

/*matrix*/
char	**cpy_matrix(char **zone, t_point size);
char	*create_line_map(char *map, int size);
char	**str_to_matrix(char *map);
void	free_matrix(char **map_matrix);

/*size*/
int		width(char *map);
int		height(char *map);
t_size	size_map(char *map);

#endif