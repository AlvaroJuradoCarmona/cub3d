/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:35:38 by fsantama          #+#    #+#             */
/*   Updated: 2023/08/22 18:18:58 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Concatenate two strings into a new string.
 *
 * This function concatenates the strings 's1' and 's2' into a new string.
 * Memory is allocated for the new string, which contains the concatenated 
 * content of 's1' followed by 's2'. The null terminator is added at the end of 
 * the new string.
 * If memory allocation fails or either input string is NULL, NULL is returned.
 *
 * @param s1 The first string.
 * @param s2 The second string.
 * @return char* A pointer to the new concatenated string, or NULL if 
 * allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	str = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = 0;
	return (str);
}
