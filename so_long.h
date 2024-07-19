/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <nmatondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:17:04 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/19 08:52:37 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include  "minilibx-linux/mlx_int.h"
# include "Libft/libft.h"
# include <fcntl.h>

typedef struct {
    void    *mlx;
    void    *win;
} t_data;

/*interfeice*/
int		key_press(int keycode, void *param);
int		close_window(void *param);

/*ler arquivo*/
char	*read_file(int	fd);
char	*open_file(const char *filename);

#endif