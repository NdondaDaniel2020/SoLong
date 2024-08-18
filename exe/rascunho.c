static void	printf_matrix(t_wind *win)
{
	int	l;
	int	c;
	t_size size;

	l = 0;
	size = size_map(win->map);
	while (l < size.h)
	{
		c = 0;
		while (c < size.w)
		{
			ft_printf("%c", win->map_matrix[l][c]);
			c++;
		}
		ft_printf("\n");
		l++;
	}
}


char	**cpy_matrix(char **zone, t_point size)
{
	int		l;
	int		c;
	char	**new;

	l = 0;
	new = malloc(sizeof(char *) * size.y);
	while (l < size.y)
	{
		c = 0;
		new[l] = malloc(size.x + 1);
		while (c < size.x)
		{
			new[l][c] = zone[l][c];
			c++;
		}
		new[l][size.x] = '\0';
		l++;
	}
	return (new);
}


		ft_printf("{%c}", win->map_matrix[point.y - 1][point.x - 1]);
		ft_printf("{%c}", win->map_matrix[point.y - 1][point.x]);
		ft_printf("{%c}\n", win->map_matrix[point.y - 1][point.x + 1]);

		ft_printf("{%c}", win->map_matrix[point.y][point.x - 1]);
		ft_printf("{%c}", win->map_matrix[point.y][point.x]);
		ft_printf("{%c}\n", win->map_matrix[point.y][point.x + 1]);

		ft_printf("{%c}", win->map_matrix[point.y + 1][point.x - 1]);
		ft_printf("{%c}", win->map_matrix[point.y + 1][point.x]);
		ft_printf("{%c}\n\n", win->map_matrix[point.y + 1][point.x + 1]);


static void	lstls(t_list *list)
{
	int	i;

	i = 0;
	if (list)
	{
		ft_printf("Lista\n");
		while (list)
		{
			ft_printf("%i - %c\n", i, *(char *)list->content);
			list = list->next;
			i++;
		}
		ft_printf("\n");
	}
}

static void	move_up(t_wind *win)
{
	t_point	point;

	if (win->move && *(char *)win->move->content == 'w')
	{
		if (condition_move(win, 0, -1))
		{
			win->cur_play[1] = 2;
			win->play_y -= 5;
			if (win->play_y % 50 == 0)
			{
				update_move_count(win);
				point = find_in_matrix(win->map_matrix, 'P');
				get_star(win, 0, -1);
				win->map_matrix[point.y][point.x] = '0';
				win->map_matrix[point.y - 1][point.x] = 'P';
				win->cur_play[1] = 0;
				lstdel_front(&win->move);
			}
		}
		else
			lstdel_front(&win->move);
	}
}


	if (*(char *)win->enemy->move->content == '2')
	{
		l = 0;
		r = 0;
		point = find_in_matrix(win->map_matrix, 'P');

		while ((win->map_matrix[point.y][point.x + r] == '0'))
			r++;
		while ((win->map_matrix[point.y][point.x + l] == '0'))
			l++;

		if (r > l)
		{
			while (r--)
			{
				ft_lstadd_back(&win->enemy->move, 
					ft_lstnew((void *)char_lst('6')));
			}
		}
		else
		{
			while (l--)
			{
				ft_lstadd_back(&win->enemy->move, 
					ft_lstnew((void *)char_lst('4')));
			}
		}
	}