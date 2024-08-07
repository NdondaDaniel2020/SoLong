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
	int	w;
	int	h;
}		t_size;

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

typedef struct s_image
{
	void	*img_ptr;
	int		w;
	int		h;
}			t_image;

typedef struct s_wind
{
	int		bg_w;
	int		bg_h;
	t_size	size;
	void	*mlx;
	void	*win;
	void	*bg;
	char	*map;
	t_image	*imgs;
	t_image	ptl[2][9];
	int		ptl_x;
	int		ptl_y;
	int		cur_ptl[2];
	t_image	player[2][3][9];
	int		play_x;
	int		play_y;
	int		cur_play[3];
	char	**map_matrix;
}			t_wind;

/*window*/
int		clean_and_exit(t_wind *win);
int		key_press(int keycode, t_wind *win);
int		is_border(t_wind *win, int l, int c);
void	init(t_wind *win);
void	master(t_wind *win);
void	draw_map(t_wind *win);
void	connection(t_wind *win);
void	clean_occurrence(t_wind *win);
void	draw_star(t_wind *win, int x, int y, int *i);
void	draw_line_map(t_wind *win, int l, int y, int *i);
void	draw_tatami_1(t_wind *win, int x, int y, int *i);
void	draw_tatami_2(t_wind *win, int x, int y, int *i);
void	draw_portal(t_wind *win, int x, int y);
void	clean_portal(t_wind *win);
void	draw_player(t_wind *win, int x, int y);
void	clean_player(t_wind *win);
int		update_portal_image(t_wind *win);
int		update_player_image(t_wind *win);
int		update_image(t_wind *win);

/*file*/
char	*open_file(const char *filename);
char	*read_file(int fd, char *str, char *buffer);

/*check map*/
int		check_map(char *map);
int		check_duplicate(char *map);
int		check_struct_map(char *map);
int		check_line(char *map_line, int *column);
t_point	find_in_matrix(char **matrix, char ch);
t_point	*find_in_all_matrix(char **matrix, char ch);

/*matrix*/
char	**str_to_matrix(char *map);
char	*create_line_map(char *map, int size);
char	**cpy_matrix(char **zone, t_point size);
void	free_matrix(char **map_matrix);

/*size*/
int		width(char *map);
int		height(char *map);
t_size	size_map(char *map);

/*grafos*/
void	fill(char **tab, t_size size, t_point cur);
void	flood_fill(char **tab, t_size size, t_point begin);
int		check_way(char *map);
int		count_occurrence(char **matrix, char ch);
int		check_matrix_reference_points(char **matrix, t_size size);
int		check_matrix_way(char **matrix, t_point cur, t_size size);

/*validator*/
void	validator_map(char *map);
void	validator_format(char *name);
char	*get_map(char *name);

/*name file*/
char	*bg1(void);
char	*bg2(void);
char	*bg3(void);
char	*star(void);
char	*tatame1(void);
char	*tatame2(void);
char	*porta_front(void);
char	*porta_back(void);
char	*format(void);
char	*side_portal(int index);
char	*side_player(int i);
char	*jump(void);
char	*idle(void);
char	*run(void);

#endif