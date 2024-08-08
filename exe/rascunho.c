
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

void	clean_portal(t_wind *win)
{
	int	l;
	int	c;

	l = 0;
	while (l < 2)
	{
		c = 0;
		while (c < 9)
		{
			win->ptl[l][c].h = 0;
			win->ptl[l][c].w = 0;
			mlx_destroy_image(win->mlx, win->ptl[l][c].img_ptr);
			c++;
		}
		l++;
	}
}

void	clean_player(t_wind *win)
{
	int	m;
	int	l;
	int	c;

	m = 0;
	while (m < 2)
	{
		l = 0;
		while (l < 3)
		{
			c = 0;
			while (c < 9)
			{
				mlx_destroy_image(win->mlx, win->player[m][l][c].img_ptr);
				c++;
			}
			l++;
		}
		m++;
	}
}


static void	add_image_to_portal(t_wind *win, int l, int c)
{
	int		w;
	int		h;
	char	*file;
	char	*num;

	num = (char *)ft_calloc(2, sizeof(char));
	num[1] = '\0';
	num[0] = ('1' + c);
	file = ft_strjoin(side_portal(l), (const char *)num);
	file = ft_strjoin_free(file, format());
	w = win->ptl[l][c].w;
	h = win->ptl[l][c].h;
	win->ptl[l][c].img_ptr = mlx_xpm_file_to_image(win->mlx, file, &w, &h);
	if (!win->ptl[l][c].img_ptr)
		clean_and_exit(win);
	free(file);
	free(num);
}

static char	*join_path(int m, int l, int c)
{
	char	*value;
	char	*file;

	value = (char *)ft_calloc(2, sizeof(char));
	value[1] = '\0';
	value[0] = ('1' + c);
	if (l == 0)
		file = ft_strjoin(side_player(m), idle());
	else if (l == 1)
		file = ft_strjoin(side_player(m), run());
	else
		file = ft_strjoin(side_player(m), jump());
	file = ft_strjoin_free(file, value);
	file = ft_strjoin_free(file, format());
	free(value);
	return (file);
}


char	*side_player(int i)
{
	if (i == 0)
		return ("img/Kunoichi-back/");
	return ("img/Kunoichi-front/");
}

char	*jump(void)
{
	return ("Jump_");
}

char	*idle(void)
{
	return ("Idle_");
}

char	*run(void)
{
	return ("Run_");
}

{
	return ("img/portal-front/portal_");
}

char	*porta_back(void)
{
	return ("img/portal-back/portal_");
}

char	*side_portal(int index)
{
	if (index == 0)
		return (porta_back());
	else
		return (porta_front());
}

char	*format(void)
{
	return (".xpm");
}