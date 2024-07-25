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
# include "minilibx_linux/mlx_int.h"
# include "Libft/libft.h"
# include <fcntl.h>

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
int		get_line_number(char *map);
int		get_column_number(char *map);
int		check_line(char *map_line, int *column);
int		check_struct_map(char *map);
int		check_map(char *map);

#endif