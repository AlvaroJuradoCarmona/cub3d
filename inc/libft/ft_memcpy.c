/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:35:00 by fsantama          #+#    #+#             */
/*   Updated: 2023/09/08 11:00:43 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copy a memory area to another memory area.
 *
 * This function copies 'n' bytes from the memory area 'src' to the memory 
 * area 'dest'. It returns a pointer to the destination memory area. The memory 
 * areas must not overlap.
 *
 * @param dest A pointer to the destination memory area.
 * @param src A pointer to the source memory area.
 * @param n The number of bytes to copy.
 * @return void* A pointer to the destination memory area 'dest'.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*c;
	char	*d;

	i = 0;
	c = (char *)dest;
	d = (char *)src;
	if (!dest && !src)
		return (0);
	while (i < n)
	{
		c[i] = d[i];
			i++;
	}
	return (dest);
}
