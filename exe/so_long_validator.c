/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_validator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <nmatondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:14:06 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/19 11:20:11 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*validator size*/
int	get_line_number(char *file_name)
{
	int		fd;
	int		i;
	char	*aux;

	i = 0;
	fd = open(file_name, O_RDONLY);
	aux = get_next_line(fd);
	if (!aux)
		return (0);
	while (aux)
	{
		aux = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i);
}

int	get_column_number(char *file_name)
{
	int		fd;
	int		i;
	char	*aux;

	i = 0;
	fd = open(file_name, O_RDONLY);
	aux = get_next_line(fd);
	if (!aux)
		return (0);
	while (aux[i] && aux[i] != '\n')
		i++;
	close(fd);
	return (i);
}


/*validator map*/
int	loop_map(char *txt)
{
	int	len;

	len = 0;
	if (!txt)
		return (0);
	len = ft_strlen(txt);
	if (txt[0] == '0' || txt[len - 2] == '0')
		return (0);
	return (1);
}

int	map_validator_value(char *file_name)
{
	int		fd;
	int		line;
	int		line_map;
	char	*txt;

	line = 0;
	fd = open(file_name, O_RDONLY);
	txt = get_next_line(fd);
	line_map = get_line_number(file_name);
	if (ft_findchar(txt, '0'))
		return (0);
	while (line != (line_map - 1))
	{
		txt = get_next_line(fd);
		if (!loop_map(txt))
			return (0);
		line++;
	}
	if (ft_findchar(txt, '0'))
		return (0);
	close(fd);
	return (1);
}

int	map_validator(char *file_name)
{
	int	column;
	int	line;
	int	valid;

	if (!file_name)
		return (0);
	valid = map_validator_value(file_name);
	column = get_column_number(file_name);
	line = get_line_number(file_name);
	if (valid && column > 6 && line > 4)
		return (1);
	return (0);
}
