/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:13:26 by fsantama          #+#    #+#             */
/*   Updated: 2023/08/22 18:17:08 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Duplicate a string.
 *
 * This function duplicates the input string 'str' by allocating memory for a 
 * new string and copying the characters from 'str' to the new string. The 
 * function returns a pointer to the new duplicated string. If memory 
 * allocation fails, NULL is returned.
 *
 * @param str The string to be duplicated.
 * @return char* A pointer to the duplicated string, or NULL if allocation 
 * 		   fails.
 */
char	*ft_strdup(const char *str)
{
	char	*dst;
	int		i;

	i = 0;
	dst = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (dst)
	{
		while (str[i])
		{
			dst[i] = str[i];
				i++;
		}
		dst[i] = 0;
	}
	else
		free (dst);
	return (dst);
}
