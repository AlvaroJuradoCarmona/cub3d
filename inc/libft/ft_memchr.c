/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:45:28 by fsantama          #+#    #+#             */
/*   Updated: 2023/08/22 17:53:19 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locate the first occurrence of a byte in a memory area.
 *
 * This function searches for the first occurrence of the byte 'c' in the first 
 * 'n' bytes of the memory area pointed to by 's'. If the byte is found, a 
 * pointer to the matching byte in memory is returned; otherwise, NULL is 
 * returned.
 *
 * @param s A pointer to the memory area to search.
 * @param c The byte to be located.
 * @param n The maximum number of bytes to search.
 * @return void* A pointer to the first occurrence of 'c' in memory, or NULL 
 * 		   if not found.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*a;

	i = 0;
	a = (unsigned char *) s;
	while (i < n)
	{
		if (a[i] == (unsigned char) c)
			return ((void *) &a[i]);
		i++;
	}
	return (0);
}
