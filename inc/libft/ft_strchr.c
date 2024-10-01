/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:54:04 by fsantama          #+#    #+#             */
/*   Updated: 2023/08/22 18:16:15 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locate the first occurrence of a character in a string.
 *
 * This function searches for the first occurrence of the character 'c' in the 
 * string 's'.
 * If the character is found, a pointer to the matching character in the string 
 * is returned.
 * If 'c' is the null terminator, a pointer to the null terminator at the end 
 * of 's' is returned.
 * If 'c' is not found in the string, NULL is returned.
 *
 * @param s A pointer to the string to search.
 * @param c The character to be located.
 * @return char* A pointer to the first occurrence of 'c' in the string, or 
 * NULL if not found.
 */
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *) &s[i]);
		i++;
	}
	if ((char) c == 0)
		return ((char *) &s[i]);
	return (0);
}
