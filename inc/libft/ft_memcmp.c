/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:07:31 by fsantama          #+#    #+#             */
/*   Updated: 2023/08/22 17:57:48 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compare two memory areas byte by byte.
 *
 * This function compares the first 'n' bytes of memory areas 's1' and 's2' 
 * byte by byte. It returns an integer value indicating the difference between 
 * the first differing bytes. If the memory areas are equal, 0 is returned.
 *
 * @param s1 A pointer to the first memory area.
 * @param s2 A pointer to the second memory area.
 * @param n The number of bytes to compare.
 * @return int A positive value if 's1' is greater, a negative value if 's2' 
 * 		   is greater, or 0 if the memory areas are equal up to the first 'n' 
 * 		   bytes.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*a;
	const unsigned char	*b;
	size_t				i;

	a = (const unsigned char *) s1;
	b = (const unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (a[i] != b[i])
			return (a[i] - b[i]);
		i++;
	}
	return (0);
}
