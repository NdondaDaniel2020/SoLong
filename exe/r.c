
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
