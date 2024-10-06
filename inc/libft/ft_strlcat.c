/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:07:38 by fsantama          #+#    #+#             */
/*   Updated: 2023/08/22 18:20:04 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Concatenate two strings with size limitation.
 *
 * This function concatenates the string 'src' onto the end of the string 
 * 'dst', ensuring that the resulting concatenated string does not exceed 
 * 'dstsize' bytes.
 * It appends the null-terminated string 'src' to the null-terminated string 
 * 'dst' and adds a null terminator at the end of the resulting string. The 
 * total length of the concatenated string is returned. If 'dstsize' is 0, 
 * the behavior is undefined.
 *
 * @param dst A pointer to the destination buffer for the concatenated string.
 * @param src A pointer to the source string to be concatenated.
 * @param dstsize The size of the destination buffer 'dst'.
 * @return size_t The total length of the concatenated string (up to 'dstsize').
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	count_dst;
	size_t	count_src;
	size_t	len_dst;

	count_dst = 0;
	count_src = 0;
	len_dst = ft_strlen(dst);
	if (len_dst < (dstsize - 1) && dstsize > 0)
	{
		while (dst[count_dst] != 0)
			count_dst++;
		while (src[count_src] != 0 && count_dst < (dstsize - 1))
		{
			dst[count_dst] = src[count_src];
			count_dst++;
			count_src++;
		}
		dst[count_dst] = 0;
	}
	if (len_dst > dstsize)
		len_dst = dstsize;
	return (len_dst + ft_strlen(src));
}
