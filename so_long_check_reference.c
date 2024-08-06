/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check_reference.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:28:27 by nmatondo          #+#    #+#             */
/*   Updated: 2024/07/31 12:40:10 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_occurrence(char **matrix, char ch)
{
	int		l;
	int		c;
	int		len;

	l = 0;
	len = 0;
	while (matrix[l])
	{
		c = 0;
		while (matrix[l][c])
		{
			if (matrix[l][c] == ch)
				len++;
			c++;
		}
		l++;
	}
	return (len);
}

t_point	*find_in_all_matrix(char **matrix, char ch)
{
	int		l;
	int		c;
	int		i;
	int		len;
	t_point	*list_point;

	l = 0;
	i = 0;
	len = count_occurrence(matrix, ch);
	list_point = (t_point *)ft_calloc(len + 1, sizeof(t_point));
	if (!list_point)
		return (NULL);
	while (matrix[l])
	{
		c = 0;
		while (matrix[l][c])
		{
			if (matrix[l][c] == ch)
				list_point[i++] = (t_point){c, l};
			c++;
		}
		l++;
	}
	list_point[i] = (t_point){-1, -1};
	return (list_point);
}

int	check_matrix_reference_points(char **matrix, t_size size)
{
	int		i;
	int		len;
	t_point	*list_occurrence;

	i = 0;
	(void)size;
	len = count_occurrence(matrix, 'C');
	list_occurrence = find_in_all_matrix(matrix, 'C');
	while (i < len)
	{
		if (!check_matrix_way(matrix, list_occurrence[i], size))
			return (0);
		i++;
	}
	i = 0;
	free(list_occurrence);
	return (1);
}
