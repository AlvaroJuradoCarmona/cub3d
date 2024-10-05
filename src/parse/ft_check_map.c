/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:29:07 by fsantama          #+#    #+#             */
/*   Updated: 2024/08/29 12:29:07 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

bool	ft_is_invalid_value(char c)
{
	return (c != '0' && c != '1' && c != ' ' && c != '2');
}

void	ft_check_map(char *map, t_data *data)
{
	t_coords	p;
	short int	flag[2];

	p.x = -1;
	p.y = 0;
	flag[0] = 0;
	flag[1] = 0;
	while (map[++p.x] && flag[0] < 2 && flag[1] < 2)
	{
		if (map[p.x] == 'N' || map[p.x] == 'S' || \
			map[p.x] == 'W' || map[p.x] == 'E')
			flag[0]++;
		else if (map[p.x] == '\n')
		{
			if (p.x - p.y + 1 > data->map_width)
				data->map_width = p.x - p.y + 1;
			p.y = p.x;
		}
		else if (ft_is_invalid_value(map[p.x]))
			flag[0] = 2;
	}
	if (flag[0] != 1 || flag[1] > 1)
		ft_error("Error: Invalid map configuration.", 0);
}
