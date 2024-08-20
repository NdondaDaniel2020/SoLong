/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmatondo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:23:41 by nmatondo          #+#    #+#             */
/*   Updated: 2024/08/08 08:13:36 by nmatondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	validator_format(char *name, char *format)
{
	int	len_n;
	int	len_f;

	len_n = ft_strlen(name);
	len_f = ft_strlen(format);
	while (format[len_f - 1] && name[len_n - 1] == format[len_f - 1])
	{
		len_f--;
		len_n--;
	}
	if (len_f != 0)
	{
		ft_printf("Formato do mapa errado\nFormato recomendado *.ber\n");
		exit(1);
	}
}

static void	validator_map(char *map)
{
	if (!check_duplicate(map))
	{
		ft_printf("Erro. verifique a quantidade de \n");
		ft_printf("caracteres valido para iniciar o Jogo\n");
		free(map);
		exit(1);
	}
	if (!check_map(map))
	{
		ft_printf("Erro no tamanho do mapa\n");
		free(map);
		exit(1);
	}
	if (!ft_findchar(map, 'C'))
	{
		ft_printf("Sem colecionaveis\n");
		free(map);
		exit(1);
	}
}

char	*get_map(char *name)
{
	char	*map;

	if (!name)
	{
		ft_printf("Mapa não encontrado\n");
		exit (1);
	}
	validator_format(name, ".ber");
	map = open_file(name);
	if (map == NULL)
	{
		ft_printf("Arquivo %s inexistente\n", name);
		exit(1);
	}
	validator_map(map);
	if (!check_way(map))
	{
		ft_printf("Sem caminho de fuga\n");
		free(map);
		exit(1);
	}
	return (map);
}
