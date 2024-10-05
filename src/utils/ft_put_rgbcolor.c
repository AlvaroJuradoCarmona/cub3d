/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_rgbcolor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 10:39:56 by ajurado-          #+#    #+#             */
/*   Updated: 2024/10/05 10:39:56 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	ft_put_rgbcolor(uint8_t *pixels, t_pixels color, bool random)
{
	pixels[0] = color.r;
	pixels[1] = color.g;
	pixels[2] = color.b;
	if (random)
	{
		pixels[3] = rand() % 106 + 150;
		return ;
	}
	pixels[3] = color.a;
}
