/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 10:58:27 by ajurado-          #+#    #+#             */
/*   Updated: 2024/10/05 10:58:27 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	ft_vertical(t_data data, int i, int j, int i1)
{
	while (--i >= 0)
	{
		if (!(data.map[i][j] == ' '))
		{
			if (data.map[i][j] == '1')
				break ;
			else
				return (1);
		}
	}
	i = i1;
	while (++i < data.map_height)
	{
		if (!(data.map[i][j] == ' '))
		{
			if (data.map[i][j] == '1')
				break ;
			else
				return (1);
		}
	}
	return (0);
}

static int	ft_horizontal(t_data data, int i, int j, int j1)
{
	while (--j >= 0)
	{
		if (!(data.map[i][j] == ' '))
		{
			if (data.map[i][j] == '1')
				break ;
			else
				return (1);
		}
	}
	j = j1;
	while (++j < (data.map_width))
	{
		if (!(data.map[i][j] == ' '))
		{
			if (data.map[i][j] == '1')
				break ;
			else
				return (1);
		}
	}
	return (0);
}

static int	check_enviroment(t_data data, int i, int j)
{
	if (ft_vertical(data, i, j, i))
		return (1);
	if (ft_horizontal(data, i, j, j))
		return (1);
	return (0);
}

static void	ft_set_player_position(t_data *data)
{
	t_coords	p;

	p.y = -1;
	while (data->map[++p.y])
	{
		p.x = -1;
		while (data->map[p.y][++p.x])
		{
			if (data->map[p.y][p.x] == 'N' || data->map[p.y][p.x] == 'S' || \
			data->map[p.y][p.x] == 'W' || data->map[p.y][p.x] == 'E')
			{
				data->player.pos.x = p.x * BLOCKSIZE + BLOCKSIZE / 2;
				data->player.pos.y = p.y * BLOCKSIZE + BLOCKSIZE / 2;
				if (data->map[p.y][p.x] == 'N')
					data->player.angle = 90 * TORADIANS;
				else if (data->map[p.y][p.x] == 'S')
					data->player.angle = 270 * TORADIANS;
				else if (data->map[p.y][p.x] == 'W')
					data->player.angle = 180 * TORADIANS;
				else
					data->player.angle = 0;
				return ;
			}
		}
	}
}

void	ft_parse_map(t_data *data)
{
	int	i;
	int	j;
	int	error;

	i = -1;
	j = -1;
	error = 0;
	while (++i < data->map_height && !error)
	{
		while (++j < data->map_width && !error)
		{
			if (data->map[i][j] == ' ')
				error = check_enviroment(*data, i, j);
		}
		j = -1;
	}
	if (error)
	{
		ft_initial_cleaner(data);
		ft_error("ERROR\n This map is not valid\n", 0);
	}
	ft_set_player_position(data);
}
