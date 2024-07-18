/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <nmatondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:17:04 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/18 14:52:35 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include  "minilibx-linux/mlx_int.h"
# include "Libft/libft.h"
# include <fcntl.h>

/*interfeice*/
int		key_press(int keycode, void *param);
int		close_window(void *param);

/*normal*/
int		ft_findchar(char *str, char c);

// char	*read_map(char *file);

#endif