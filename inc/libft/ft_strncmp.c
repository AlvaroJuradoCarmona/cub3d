/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:42:57 by fsantama          #+#    #+#             */
/*   Updated: 2024/03/18 16:35:09 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compare two strings up to a specified number of characters.
 *
 * This function compares the strings 's1' and 's2' up to the first 'n' 
 * characters or until a null terminator is reached, whichever comes first. 
 * The comparison is done based on the ASCII values of the characters. 
 * The function returns an integer value:
 * - 0 if both strings are equal up to 'n' characters or null terminator.
 * - A positive value if the first differing character in 's1' is greater 
 * than in 's2'.
 * - A negative value if the first differing character in 's1' is smaller 
 * than in 's2'.
 *
 * @param s1 The first string to be compared.
 * @param s2 The second string to be compared.
 * @param n The maximum number of characters to compare.
 * @return int An integer indicating the result of the comparison.
 */
int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int		i;
	int		r;

	i = 0;
	r = 0;
	while (r == 0 && (s2[i] || s1[i]) && i < n)
	{
		r = (unsigned char)s1[i] - (unsigned char)s2[i];
		i++;
	}
	return (r);
}
