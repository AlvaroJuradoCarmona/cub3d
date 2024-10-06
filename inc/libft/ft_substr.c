/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:48:16 by fsantama          #+#    #+#             */
/*   Updated: 2023/08/22 18:50:16 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Extract a substring from a string.
 *
 * This function extracts a substring from the string 's', starting from the 
 * index 'start' and containing up to 'len' characters. The extracted substring 
 * is returned as a new dynamically allocated string. If 's' is NULL, NULL is 
 * returned. If 'start' is beyond the length of 's', an empty string is 
 * returned. If 'len' exceeds the available characters in the substring, 'len' 
 * is adjusted to fit within the substring length. Memory is allocated for the 
 * new substring.
 *
 * @param s A pointer to the string from which the substring is extracted.
 * @param start The starting index of the substring.
 * @param len The maximum number of characters in the substring.
 * @return char* A pointer to the new substring, or NULL if allocation fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (0);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	ft_memcpy(str, &s[start], len);
	str[len] = 0;
	return (str);
}
