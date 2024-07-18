/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rascunho.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <nmatondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 09:14:30 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/17 14:09:58 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include <fcntl.h>

/*find char*/
int	ft_findchar(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		++str;
	}
	return (0);
}

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

int map_validator(char *file_name)
{
	int	column;
	int line;
	int	valid;
	
	valid = map_validator_value(file_name);
	column = get_column_number(av[1]);
	line = get_line_number(av[1]);
	if ( valid && column > 6 && line > 6)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	ft_printf("\n%i %s", map_validator_value(av[1]), av[1]);
	ft_printf("\n%i %i", get_column_number(av[1]), get_line_number(av[1]));
}
