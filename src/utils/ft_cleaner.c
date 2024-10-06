/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleaner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 10:57:34 by ajurado-          #+#    #+#             */
/*   Updated: 2024/10/05 10:57:38 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	ft_img_failure(t_data *data)
{
	mlx_close_window(data->mlx);
	ft_error("Error\nImage/Texture failure", 0);
	ft_initial_cleaner(data);
	exit(EXIT_FAILURE);
}
