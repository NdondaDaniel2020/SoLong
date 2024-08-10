
void	move_player(t_wind *win, int x, int y);
{
	void	*img;

	img = win->player[win->cur_play].img_ptr;
	mlx_put_image_to_window(win->mlx, win->win, img, x, y);
}

void	move_player(t_wind *win, int x, int y);
{
	void	*img;

	img = win->player[win->cur_play].img_ptr;
	mlx_put_image_to_window(win->mlx, win->win, img, x, y);
}

static int	condition_move(t_wind *win, int x, int y)
{
	int		c;
	t_point	point;

	c = count_occurrence(win->map_matrix, 'C');
	point = find_in_matrix(win->map_matrix, 'P');
	if (win->map_matrix[point.y + y][point.x + x] == '0')
		return (1);
	if (win->map_matrix[point.y + y][point.x + x] == 'C')
		return (1);
	if (win->map_matrix[point.y + y][point.x + x] == 'E' && c == 0)
		clean_and_exit(win);
	return (0);
}

void	move_left(t_wind *win)
{
	t_point	point;

	if (condition_move(win, -1, 0))
	{
		win->cur_play = 0;
		point = find_in_matrix(win->map_matrix, 'P');
		win->map_matrix[point.y][point.x] = '0';
		win->map_matrix[point.y][point.x - 1] = 'P';
		draw_empty(win, win->play_x, win->play_y);
		win->play_x -= 50;
		win->move += 1;
		ft_printf("move: %i\n", win->move);
		move_player(win, win->play_x, win->play_y);
	}
}

void	move_right(t_wind *win)
{
	t_point	point;

	if (condition_move(win, 1, 0))
	{
		win->cur_play = 1;
		point = find_in_matrix(win->map_matrix, 'P');
		win->map_matrix[point.y][point.x] = '0';
		win->map_matrix[point.y][point.x + 1] = 'P';
		draw_empty(win, win->play_x, win->play_y);
		win->play_x += 50;
		win->move += 1;
		ft_printf("move: %i\n", win->move);
		move_player(win, win->play_x, win->play_y);
	}
}

void	move_up(t_wind *win)
{
	t_point	point;

	if (condition_move(win, 0, -1))
	{
		point = find_in_matrix(win->map_matrix, 'P');
		win->map_matrix[point.y][point.x] = '0';
		win->map_matrix[point.y - 1][point.x] = 'P';
		draw_empty(win, win->play_x, win->play_y);
		win->play_y -= 50;
		win->move += 1;
		ft_printf("move: %i\n", win->move);
		move_player(win, win->play_x, win->play_y);
	}
}

void	move_down(t_wind *win)
{
	t_point	point;

	if (condition_move(win, 0, 1))
	{
		point = find_in_matrix(win->map_matrix, 'P');
		win->map_matrix[point.y][point.x] = '0';
		win->map_matrix[point.y + 1][point.x] = 'P';
		draw_empty(win, win->play_x, win->play_y);
		win->play_y += 50;
		win->move += 1;
		ft_printf("move: %i\n", win->move);
		move_player(win, win->play_x, win->play_y);
	}
}


	if (keycode == 65363)
		move_right(win);
	if (keycode == 65361)
		move_left(win);
	if (keycode == 65362)
		move_up(win);
	if (keycode == 65364)
		move_down(win);

void	ft_lstremove(t_list **list, char ch)
{
	t_list	*aux;
	t_list	*removed;

	if (*list)
	{
		if (*(char *)(*list)->content == ch)
		{
			removed = *list;
			*list = removed->next;
			free(removed);
		}
		else
		{
			aux = *list;
			while (aux->next && *(char *)aux->next->content != ch)
				aux = aux->next;
			if (aux->next)
			{
				removed = aux->next;
				aux->next = removed->next;
				free(removed);
			}
		}
	}
}

int	main(void)
{
	t_list	*list;

	list = NULL;
	ft_lstadd_back(&list, ft_lstnew((void *)ft_char_lst('a')));
	ft_lstadd_back(&list, ft_lstnew((void *)ft_char_lst('w')));
	ft_lstadd_back(&list, ft_lstnew((void *)ft_char_lst('d')));

	lstls(list);
	lstdel_front(&list);
	lstls(list);
	lstdel_front(&list);
	lstls(list);
	lstdel_front(&list);
	lstls(list);
	lstdel_front(&list);
	lstls(list);
}
