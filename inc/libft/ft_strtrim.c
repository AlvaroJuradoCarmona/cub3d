/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:36:02 by fsantama          #+#    #+#             */
/*   Updated: 2023/08/22 18:49:13 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Trim characters from the beginning and end of a string.
 *
 * This function creates a new string by removing characters from the 
 * beginning and end of 's1' that match any characters in the 'set' string. 
 * The new string is returned. If 's1' or 'set' is NULL, NULL is returned. 
 * If 's1' is empty or contains only characters in 'set', an empty string is 
 * returned.
 *
 * @param s1 A pointer to the string to be trimmed.
 * @param set A pointer to the string containing characters to be trimmed.
 * @return char* A pointer to the new string with trimmed characters, or NULL 
 * if allocation fails.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	count;
	size_t	len;

	count = 0;
	len = ft_strlen(s1);
	if (!s1 || !set)
		return (0);
	if (s1[count] == 0 || len == 0)
		return (ft_strdup(""));
	while (ft_strchr(set, s1[count]))
		count++;
	while (ft_strchr(set, s1[len]))
		len--;
	return (ft_substr(s1, count, len - count + 1));
}
