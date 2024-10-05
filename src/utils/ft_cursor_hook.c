#include "../../inc/cub3d.h"

static void	finish(t_data *data)
{
	char		*str;

	data->pause = 1;
	data->player.img->enabled = 0;
	data->galaxy_i->enabled = 0;
	data->player.ray_img->enabled = 0;
	data->time->instances->x = WIDTH / 2 - 30;
	data->time->instances->y = HEIGHT / 2;
	mlx_delete_image(data->mlx, data->time);
	data->time = mlx_put_string(data->mlx, str, WIDTH / 2 - 30, HEIGHT / 2);
	ft_free_and_null((void **)&str);
}

void	ft_move(t_data *data, t_coords pos, double x, double y)
{
	int			j;
	int			i;

	i = 3;
	pos.x += x * i;
	pos.y += y * i;
	j = ft_check_player_abroad(pos, data, 1);
	while ((j == 0 || (j == 2 && data->door_open == 1) || \
	j == 3) && ++i < VELOCITY)
	{
		if (j == 3)
			return (finish(data));
		pos.x = data->player.pos.x + x * i;
		pos.y = data->player.pos.y + y * i;
		j = ft_check_player_abroad(pos, data, 1);
	}
	if (i <= 3)
		return ;
	data->player.pos.x = pos.x;
	data->player.pos.y = pos.y;
	ft_redraw(data, 0);
	if (j == 2)
		data->pass_door = 1;
}

void	ft_redraw(t_data *data, double angle)
{
	if (angle != 0)
	{
		data->player.angle += angle;
		data->galaxy_i->instances->x -= (int)(angle * 300);
		if (data->galaxy_i->instances->x > 0)
			data->galaxy_i->instances->x = 1920 - data->galaxy_i->width;
		else if (data->galaxy_i->instances->x < (int32_t)(1920 - \
			data->galaxy_i->width))
			data->galaxy_i->instances->x = 0;
	}
	raycasting(data, data->player.pos);
}

void	ft_cursor_hook(double x2, double y2, void *param)
{
	t_data		*data;
	static double	x1 = 0;
	static int		i = 0;

	data = param;
	i++;
	if (!data->cursor_hook || i < 2 || data->pause == 1)
		return ;
	i = 0;
	ft_redraw(data, (x2 - x1) * 0.001745);
	x1 = x2;
	(void)y2;
}
