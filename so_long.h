/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:17:04 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
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

typedef struct s_enemy
{
	t_image	enemy[2][4][6];
	int		cur_enmy[3];
	int		enmy_x;
	int		enmy_y;
	t_list	*move;
}	t_enemy;

typedef struct s_wind
{
	void	*mlx;
	void	*win;
	char	*map;
	char	**map_matrix;
	t_enemy	*enemy;	
	t_image	bg_img;
	t_image	star;
	t_image	block[2];
	t_size	size;
	t_image	ptl[2][9];
	int		cur_ptl[2];
	int		ptl_x;
	int		ptl_y;
	t_list	*move;
	t_image	player[2][3][9];
	int		cur_play[3];
	int		play_x;
	int		play_y;
	int		move_count;
	int		star_count;
	int		diagonal_r;
	int		diagonal_l;
}			t_wind;

/*window*/
int		key_press(int keycode, t_wind *win);
int		is_border(t_wind *win, int l, int c);
void	key_pess_enemy(int key, t_wind *win);
void	draw_map(t_wind *win);
void	connection(t_wind *win);

void	upload_images(t_wind *win);
void	upload_images3(t_wind *win);
void	upload_images4(t_wind *win);

void	draw_map(t_wind *win);
void	draw_empty(t_wind *win, int x, int y);

void	draw_player(t_wind *win, int l, int y);
void	draw_portal(t_wind *win, int l, int y);

int		clean(t_wind *win);
int		clean_and_exit(t_wind *win);
void	clean_portal(t_wind *win);
void	clean_player(t_wind *win);
void	clean_command(t_wind *win);
void	clean_enemy(t_wind *win);
void	clean_command_enemy(t_list **list);

void	init_portal(t_wind *win);
void	init_player(t_wind *win);

int		update_image(t_wind *win);
void	update_move_count(t_wind *win);
void	update_star_count(t_wind *win);

/* list */
void	lstdel_front(t_list **list);
char	*char_lst(char ch);

void	move_player(t_wind *win);
void	move_up(t_wind *win);
int		movement_blocked_left(t_wind *win);
int		movement_blocked_right(t_wind *win);
int		condition_move(t_wind *win, int x, int y);
int		condition_move_top_right(t_wind *win, t_point point);
int		condition_move_top_left(t_wind *win, t_point point);

void	move_enemy(t_wind *win);

void	get_star(t_wind *win, int x, int y);

/*file*/
char	*open_file(const char *filename);

/*check map*/
int		check_map(char *map);
int		check_duplicate(char *map);
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
int		check_way(char *map);
int		count_occurrence(char **matrix, char ch);
int		check_matrix_reference_points(char **matrix, t_size size);
int		check_matrix_way(char **matrix, t_point cur, t_size size);

/*validator*/
char	*get_map(char *name);

/*name file*/
char	*star(void);
char	*empty(void);
char	*tatame1(void);
char	*tatame2(void);
char	*side_player(int i);
char	*side_portal(int index);

char	*format(void);
char	*jump(void);
char	*idle(void);
char	*run(void);
char	*attack(void);
char	*death(void);
char	*side_enemy(int index);

#endif