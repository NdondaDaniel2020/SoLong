	// path = player_back();
	// w = win->player[0].w;
	// h = win->player[0].h;
	// win->player[0].img_ptr = mlx_xpm_file_to_image(win->mlx, path, &w, &h);
	// path = player_front();
	// w = win->player[1].w;
	// h = win->player[1].h;
	// win->player[1].img_ptr = mlx_xpm_file_to_image(win->mlx, path, &w, &h);



// void	draw_player(t_wind *win, int l, int y);
// {
// 	int		c;
// 	int		x;
// 	// int		pos;
// 	// void	*img;

// 	c = 0;
// 	x = 0;
// 	while (win->map_matrix[l][c])
// 	{
// 		if (win->map_matrix[l][c] == 'P')
// 		{
// 			win->play_x = x;
// 			win->play_y = y;
// 			// pos = pos_player(win);
// 			// win->cur_play = pos;
// 			// img = win->player[pos].img_ptr;
// 			// mlx_put_image_to_window(win->mlx, win->win, img, x, y);
// 		}
// 		x += 50;
// 		c++;
// 	}
// }

// static int	pos_portal(t_wind *win);
// {
// 	int		r;
// 	int		l;
// 	t_point	pos;

// 	r = 1;
// 	l = 1;
// 	pos = find_in_matrix(win->map_matrix, 'E');
// 	while (win->map_matrix[pos.y][pos.x + r] == '0')
// 		r++;
// 	while (win->map_matrix[pos.y][pos.x - l] == '0')
// 		l++;
// 	if (l > r)
// 		return (1);
// 	else
// 		return (0);
// static int	condition_move(t_wind *win, int x, int y)
// {
// 	int		c;
// 	t_point	point;

// 	c = count_occurrence(win->map_matrix, 'C');
// 	point = find_in_matrix(win->map_matrix, 'P');
// 	if (win->map_matrix[point.y + y][point.x + x] == '0')
// 		return (1);
// 	if (win->map_matrix[point.y + y][point.x + x] == 'C')
// 		return (1);
// 	if (win->map_matrix[point.y + y][point.x + x] == 'E' && c == 0)
// 		clean_and_exit(win);
// 	return (0);
// }

// void	move_left(t_wind *win)
// {
// 	t_point	point;

// 	if (condition_move(win, -1, 0))
// 	{
// 		win->cur_play = 0;
// 		point = find_in_matrix(win->map_matrix, 'P');
// 		win->map_matrix[point.y][point.x] = '0';
// 		win->map_matrix[point.y][point.x - 1] = 'P';
// 		draw_empty(win, win->play_x, win->play_y);
// 		win->play_x -= 50;
// 		win->move += 1;
// 		ft_printf("move: %i\n", win->move);
// 		move_player(win, win->play_x, win->play_y);
// 	}
// }

// void	move_right(t_wind *win)
// {
// 	t_point	point;

// 	if (condition_move(win, 1, 0))
// 	{
// 		win->cur_play = 1;
// 		point = find_in_matrix(win->map_matrix, 'P');
// 		win->map_matrix[point.y][point.x] = '0';
// 		win->map_matrix[point.y][point.x + 1] = 'P';
// 		draw_empty(win, win->play_x, win->play_y);
// 		win->play_x += 50;
// 		win->move += 1;
// 		ft_printf("move: %i\n", win->move);
// 		move_player(win, win->play_x, win->play_y);
// 	}
// }

// void	move_up(t_wind *win)
// {
// 	t_point	point;

// 	if (condition_move(win, 0, -1))
// 	{
// 		point = find_in_matrix(win->map_matrix, 'P');
// 		win->map_matrix[point.y][point.x] = '0';
// 		win->map_matrix[point.y - 1][point.x] = 'P';
// 		draw_empty(win, win->play_x, win->play_y);
// 		win->play_y -= 50;
// 		win->move += 1;
// 		ft_printf("move: %i\n", win->move);
// 		move_player(win, win->play_x, win->play_y);
// 	}
// }

// void	move_down(t_wind *win)
// {
// 	t_point	point;

// 	if (condition_move(win, 0, 1))
// 	{
// 		point = find_in_matrix(win->map_matrix, 'P');
// 		win->map_matrix[point.y][point.x] = '0';
// 		win->map_matrix[point.y + 1][point.x] = 'P';
// 		draw_empty(win, win->play_x, win->play_y);
// 		win->play_y += 50;
// 		win->move += 1;
// 		ft_printf("move: %i\n", win->move);
// 		move_player(win, win->play_x, win->play_y);
// 	}
// }

// }

void	draw_portal(t_wind *win, int l, int y);
// {
// 	int	nt		pos;
// 	// void	*img;

// 	c = 0;
// 	x = 0;
// 	while (win->map_matrix[l][c])
// 	{
// 		if (win->map_matrix[l][c] == 'E')
// 		{
// 			// pos = pos_portal(win);
// 			// img = win->ptl[pos].img_ptr;
// 			// mlx_put_image_to_window(win->mlx, win->win, img, x, y);
// 		}
// 		x += 50;
// 		c++;
// 	}
// }

void	move_player(t_wind *win, int x, int y);
// {
// 	void	*img;

// 	img = win->player[win->cur_play].img_ptr;
// 	mlx_put_image_to_window(win->mlx, win->win, img, x, y);
// }	c;
// 	int		x;
// 	// int		pos;
// 	// void	*img;

// 	c = 0;
// 	x = 0;
// 	while (win->map_matrix[l][c])
// 	{
// 		if (win->map_matrix[l][c] == 'E')
// 		{
// 			// pos = pos_portal(win);
// 			// img = win->ptl[pos].img_ptr;
// 			// mlx_put_image_to_window(win->mlx, win->win, img, x, y);
// 		}
// 		x += 50;
// 		c++;
// 	}
// }

void	move_player(t_wind *win, int x, int y);
// {
// 	void	*img;

// 	img = win->player[win->cur_play].img_ptr;
// 	mlx_put_image_to_window(win->mlx, win->win, img, x, y);
// }



// static int	condition_move(t_wind *win, int x, int y)
// {
// 	int		c;
// 	t_point	point;

// 	c = count_occurrence(win->map_matrix, 'C');
// 	point = find_in_matrix(win->map_matrix, 'P');
// 	if (win->map_matrix[point.y + y][point.x + x] == '0')
// 		return (1);
// 	if (win->map_matrix[point.y + y][point.x + x] == 'C')
// 		return (1);
// 	if (win->map_matrix[point.y + y][point.x + x] == 'E' && c == 0)
// 		clean_and_exit(win);
// 	return (0);
// }

// void	move_left(t_wind *win)
// {
// 	t_point	point;

// 	if (condition_move(win, -1, 0))
// 	{
// 		win->cur_play = 0;
// 		point = find_in_matrix(win->map_matrix, 'P');
// 		win->map_matrix[point.y][point.x] = '0';
// 		win->map_matrix[point.y][point.x - 1] = 'P';
// 		draw_empty(win, win->play_x, win->play_y);
// 		win->play_x -= 50;
// 		win->move += 1;
// 		ft_printf("move: %i\n", win->move);
// 		move_player(win, win->play_x, win->play_y);
// 	}
// }

// void	move_right(t_wind *win)
// {
// 	t_point	point;

// 	if (condition_move(win, 1, 0))
// 	{
// 		win->cur_play = 1;
// 		point = find_in_matrix(win->map_matrix, 'P');
// 		win->map_matrix[point.y][point.x] = '0';
// 		win->map_matrix[point.y][point.x + 1] = 'P';
// 		draw_empty(win, win->play_x, win->play_y);
// 		win->play_x += 50;
// 		win->move += 1;
// 		ft_printf("move: %i\n", win->move);
// 		move_player(win, win->play_x, win->play_y);
// 	}
// }

// void	move_up(t_wind *win)
// {
// 	t_point	point;

// 	if (condition_move(win, 0, -1))
// 	{
// 		point = find_in_matrix(win->map_matrix, 'P');
// 		win->map_matrix[point.y][point.x] = '0';
// 		win->map_matrix[point.y - 1][point.x] = 'P';
// 		draw_empty(win, win->play_x, win->play_y);
// 		win->play_y -= 50;
// 		win->move += 1;
// 		ft_printf("move: %i\n", win->move);
// 		move_player(win, win->play_x, win->play_y);
// 	}
// }

// void	move_down(t_wind *win)
// {
// 	t_point	point;

// 	if (condition_move(win, 0, 1))
// 	{
// 		point = find_in_matrix(win->map_matrix, 'P');
// 		win->map_matrix[point.y][point.x] = '0';
// 		win->map_matrix[point.y + 1][point.x] = 'P';
// 		draw_empty(win, win->play_x, win->play_y);
// 		win->play_y += 50;
// 		win->move += 1;
// 		ft_printf("move: %i\n", win->move);
// 		move_player(win, win->play_x, win->play_y);
// 	}
// }
