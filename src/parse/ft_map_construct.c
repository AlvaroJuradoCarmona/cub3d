/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_construct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 10:56:35 by ajurado-          #+#    #+#             */
/*   Updated: 2024/10/05 10:56:35 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	ft_draw_square(t_data *data, t_coords p, t_pixels color)
{
	int			i;
	int			j;

	p.x *= BLOCKSIZE;
	p.y *= BLOCKSIZE;
	if (p.x < 0)
		p.x = 0;
	if (p.y < 0)
		p.y = 0;
	if (p.x + BLOCKSIZE > data->map_close.width)
		p.x = data->map_close.width - BLOCKSIZE;
	if (p.y + BLOCKSIZE > data->map_close.height)
		p.y = data->map_close.height - BLOCKSIZE;
	i = p.y - 1;
	while (++i < p.y + BLOCKSIZE)
	{
		j = p.x - 1;
		while (++j < p.x + BLOCKSIZE)
			ft_put_rgbcolor(&(data->map_close.img[(i * \
		data->map_close.width + j) * 4]), color, 1);
	}
}

static void	ft_draw_map(t_data *data)
{
	t_coords	p;

	p.y = -1;
	while (data->map[++p.y])
	{
		p.x = -1;
		while (data->map[p.y][++p.x])
		{
			if (data->map[p.y][p.x] == '1')
				ft_draw_square(data, p, data->color.white);
			else if (data->map[p.y][p.x] == '0' ||
data->map[p.y][p.x] == 'N' || data->map[p.y][p.x] == 'S' ||
data->map[p.y][p.x] == 'W' || data->map[p.y][p.x] == 'E')
				ft_draw_square(data, p, data->color.blue);
			else if (data->map[p.y][p.x] == '2')
				ft_draw_square(data, p, data->color.red);
		}
	}
}

void	ft_map_construct(t_data *data)
{
	int	i;

	ft_memset(data->map_close.img, 200, data->map_close.width * \
	data->map_close.height * sizeof(int));
	ft_draw_map(data);
	i = 0;
	while (i < data->map_close.height * data->map_close.rwidth)
	{
		if (data->map_close.img[i] != 104)
		{
			data->map_open.img[i] = data->map_close.img[i];
			data->map_open.img[i + 1] = data->map_close.img[i + 1];
			data->map_open.img[i + 2] = data->map_close.img[i + 2];
			data->map_open.img[i + 3] = data->map_close.img[i + 3];
		}
		else
			ft_put_rgbcolor(&data->map_open.img[i], data->color.green, 1);
		i += 4;
	}
	raycasting(data, data->player.pos);
}
