/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:17:04 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/31 11:40:06 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx_linux/mlx.h"
# include "minilibx_mms/mlx.h"
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
	int		w;
	int		h;
	void	*mlx;
	void	*win;
	void	*bg;
	char	*map;
	char	**map_matrix;
}			t_wind;

/*window*/
int		key_press(int keycode, t_wind *window);
int		clean_and_exit(t_wind *window);
void	add_background(t_wind *window, char *map);
void	connection(t_wind *window);
void	init(t_wind *window);
t_size	size_image_background(char *map);

/*file*/
char	*read_file(int fd, char *str, char *buffer);
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

/*grafos*/
void	fill(char **tab, t_size size, t_point cur);
void	flood_fill(char **tab, t_size size, t_point begin);
int		check_matrix_reference_points(char **matrix, t_size size);
int		check_matrix_way(char **matrix, t_point cur, t_size size);
int		check_way(char *map);

/*validator*/
void	validator_format(char *name);
void	validator_map(char *map);
char	*get_map(char *name);

/*name file*/
char	*bg1(void);
char	*bg2(void);
char	*bg3(void);

/*master*/
void	master(t_wind *window);

#endif
