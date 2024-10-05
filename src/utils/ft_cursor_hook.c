/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cursor_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 10:36:04 by ajurado-          #+#    #+#             */
/*   Updated: 2024/10/05 12:46:00 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	finish(t_data *data)
{
	char		*str;

	data->pause = 1;
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
}

void	ft_redraw(t_data *data, double angle)
{
	if (angle != 0)
	{
		data->player.angle += angle;
	}
	raycasting(data, data->player.pos);
}
