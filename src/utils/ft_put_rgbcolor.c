/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_rgbcolor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 09:55:09 by fsantama          #+#    #+#             */
/*   Updated: 2024/10/02 10:02:04 by fsantama         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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