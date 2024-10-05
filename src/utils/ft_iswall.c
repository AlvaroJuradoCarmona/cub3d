/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 10:43:38 by ajurado-          #+#    #+#             */
/*   Updated: 2024/10/05 10:43:42 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	ft_iswall(t_coords p, t_data *data)
{
	t_coords	pcasted;

	pcasted.x = p.x / BLOCKSIZE;
	pcasted.y = p.y / BLOCKSIZE;
	if (pcasted.x >= data->map_width || pcasted.y >= data->map_height || \
	pcasted.x < 0 || pcasted.y < 0)
		return (1);
	else if (data->map[pcasted.y][pcasted.x] == '1')
		return (1);
	else if (data->map[pcasted.y][pcasted.x] == '2')
		return (2);
	return (0);
}
