/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initial_cleaner.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 09:35:31 by fsantama          #+#    #+#             */
/*   Updated: 2024/09/02 09:35:31 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	ft_initial_cleaner(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 6)
		ft_free_and_null((void **)&data->iden[i]);
	ft_split_free(data->map);
	ft_free_and_null((void **)&data->map_close.img);
	ft_free_and_null((void **)&data->map_open.img);
}
