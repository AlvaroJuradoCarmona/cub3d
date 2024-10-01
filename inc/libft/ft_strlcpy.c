/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:57:14 by fsantama          #+#    #+#             */
/*   Updated: 2023/08/22 18:43:49 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copy a string with size limitation.
 *
 * This function copies up to 'size - 1' characters from the null-terminated 
 * string 'src' to the null-terminated string 'dst'. The resulting copied 
 * string in 'dst' is null-terminated.
 * The total length of the source string 'src' is returned. If 'size' is 0, 
 * the behavior is undefined.
 *
 * @param dst A pointer to the destination buffer for the copied string.
 * @param src A pointer to the source string to be copied.
 * @param size The size of the destination buffer 'dst'.
 * @return size_t The total length of the source string 'src'.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (i < (size - 1) && src[i] != 0)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	return (ft_strlen(src));
}
