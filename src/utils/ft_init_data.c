/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 09:25:04 by fsantama          #+#    #+#             */
/*   Updated: 2024/07/25 09:25:04 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void    ft_init_data(t_data *data)
{
    /*
    int	i;

	i = -1;
	while (++i < 6)
		data->ids[i] = NULL;
        */
	data->map_close.img = NULL;
	data->map_open.img = NULL;
	data->screen_width = 0;
	data->screen_height = 0;
	data->pause = 0;
	data->door_open = 0;
	data->pass_door = 0;
	data->cursor_hook = 0;
//	init_colors(data);
}