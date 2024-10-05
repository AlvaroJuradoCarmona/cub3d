/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 10:32:44 by ajurado-          #+#    #+#             */
/*   Updated: 2024/10/05 10:32:58 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	ft_check_player_abroad(t_coords p, t_data *data, bool doors)
{
	t_coords	p_abroad[4];
	int			i;
	int			value;

	p_abroad[0].x = p.x + PLAYER_SIZE;
	p_abroad[0].y = p.y;
	p_abroad[1].x = p.x - PLAYER_SIZE;
	p_abroad[1].y = p.y;
	p_abroad[2].x = p.x;
	p_abroad[2].y = p.y + PLAYER_SIZE;
	p_abroad[3].x = p.x;
	p_abroad[3].y = p.y - PLAYER_SIZE;
	i = -1;
	value = 0;
	if (!doors)
	{
		while (++i < 4 && value == 0)
			value = ft_iswall(p_abroad[i], data);
		return (value);
	}
	while ((++i < 4 && value == 0) || (i < 4 && value == 2 && data->door_open))
		value = ft_iswall(p_abroad[i], data);
	return (value);
}

static void	ft_vision_hooks(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		ft_redraw(data, -0.1745);
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		ft_redraw(data, 0.1745);
	if (mlx_is_key_down(data->mlx, MLX_KEY_0) && !data->cursor_hook)
	{
		data->cursor_hook = 1;
		mlx_set_cursor_mode(data->mlx, MLX_MOUSE_DISABLED);
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_1) && data->cursor_hook)
	{
		data->cursor_hook = 0;
		mlx_set_cursor_mode(data->mlx, MLX_MOUSE_NORMAL);
	}
}

static void	ft_movement_hooks(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		ft_move(data, data->player.pos, \
cos(data->player.angle + PI), sin(data->player.angle + PI));
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		ft_move(data, data->player.pos, \
cos(data->player.angle), sin(data->player.angle));
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		ft_move(data, data->player.pos, \
sin(data->player.angle + PI), -cos(data->player.angle + PI));
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		ft_move(data, data->player.pos, \
sin(data->player.angle), -cos(data->player.angle));
}

static void	ft_doors_hooks(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_SPACE))
	{
		if (data->door_open == 0 && data->open_coldown <= 0)
		{
			ft_swap(&data->map_close.img, &data->map_open.img, \
			sizeof(uint8_t *));
			data->door_open = 1;
			ft_move(data, data->player.pos, 0, 0);
		}
	}
	if (data->door_open == 1 && data->open_coldown == 0)
	{
		if (ft_check_player_abroad(data->player.pos, data, 0) != 0)
			return ;
		data->door_open = 0;
		ft_swap(&data->map_close.img, &data->map_open.img, sizeof(uint8_t *));
		ft_move(data, data->player.pos, 0, 0);
	}
}

void	ft_keyboard_hooks(void *param)
{
	t_data	*data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (data->pause == 1)
		return ;
	ft_movement_hooks(data);
	ft_vision_hooks(data);
	ft_doors_hooks(data);
}
