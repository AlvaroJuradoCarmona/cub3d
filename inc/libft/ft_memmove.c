/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:21:05 by fsantama          #+#    #+#             */
/*   Updated: 2023/08/22 17:59:27 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Move a memory area to another memory area, handling overlaps.
 *
 * This function moves 'n' bytes from the memory area 'src' to the memory area 
 * 'dest'. It handles overlapping memory areas correctly, ensuring a reliable 
 * copy operation. The function returns a pointer to the destination memory 
 * area.
 *
 * @param dest A pointer to the destination memory area.
 * @param src A pointer to the source memory area.
 * @param n The number of bytes to move.
 * @return void* A pointer to the destination memory area 'dest'. 
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*a;
	char	*b;

	i = 0;
	a = (char *)dest;
	b = (char *)src;
	if (!dest && !src)
		return (0);
	if (a > b)
	{
		while (n -- > 0)
		{
			a[n] = b[n];
		}
	}
	else
	{
		while (i < n)
		{
			a[i] = b[i];
			i++;
		}
	}
	return (dest);
}
