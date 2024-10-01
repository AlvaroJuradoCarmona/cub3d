/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:19:52 by fsantama          #+#    #+#             */
/*   Updated: 2023/08/22 18:06:14 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Fill a memory area with a specified byte value.
 *
 * This function fills the first 'n' bytes of the memory area pointed to by 's'
 * with the specified byte value 'c'. It returns a pointer to the filled 
 * memory area.
 *
 * @param s A pointer to the memory area to be filled.
 * @param c The byte value to be set.
 * @param n The number of bytes to fill.
 * @return void* A pointer to the filled memory area 's'.
 */
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*b;
	size_t			i;

	b = s;
	i = 0;
	while (i < n)
	{
		b[i] = c;
		i++;
	}
	return ((void *)b);
}
