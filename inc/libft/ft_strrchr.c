/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:34:53 by fsantama          #+#    #+#             */
/*   Updated: 2023/08/22 18:48:21 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locate the last occurrence of a character in a string.
 *
 * This function searches for the last occurrence of the character 'c' within 
 * the string 's'.
 * It iterates through 's' in reverse order and returns a pointer to the last 
 * occurrence of 'c'.
 * If 'c' is not found in 's', NULL is returned.
 *
 * @param s A pointer to the string to be searched.
 * @param c The character to be located.
 * @return char* A pointer to the last occurrence of 'c' within 's', or NULL 
 * if not found.
 */
char	*ft_strrchr(const char *s, int c)
{
	int	count;

	count = 0;
	while (s[count] != 0)
		count++;
	while (count > 0)
	{
		if (s[count] == (char) c)
			return ((char *) &s[count]);
		count--;
	}
	if ((char) c == s[count])
		return ((char *) &s[count]);
	return (0);
}
