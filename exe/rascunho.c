
int	update_player_image(t_wind *win)
{
	int		x;
	int		y;
	int		cur[3];
	void	*img;

	(void)win;
	x = win->play_x;
	y = win->play_y;
	cur[0] = win->cur_play[0];
	cur[1] = win->cur_play[1];
	cur[2] = win->cur_play[2];
	img = win->player[cur[0]][cur[1]][cur[2]].img_ptr;
	if (img == NULL)
		clean_and_exit(win);
	win->cur_play[2] = (win->cur_play[2] + 1) % 9;
	mlx_put_image_to_window(win->mlx, win->win, img, x, y);
	usleep(90000);
	return (0);
}

int	update_portal_image(t_wind *win)
{
	int		x;
	int		y;
	void	*img;

	x = win->ptl_x;
	y = win->ptl_y;
	img = win->ptl[win->cur_ptl[0]][win->cur_ptl[1]].img_ptr;
	win->cur_ptl[1] = (win->cur_ptl[1] + 1) % 9;
	mlx_put_image_to_window(win->mlx, win->win, img, x, y);
	usleep(20000);
	return (0);
}

int	update_image(t_wind *win)
{
	update_portal_image(win);
	update_player_image(win);
	return (0);
}
