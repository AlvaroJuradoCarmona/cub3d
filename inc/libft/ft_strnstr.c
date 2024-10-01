/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:52:01 by fsantama          #+#    #+#             */
/*   Updated: 2023/08/22 18:47:30 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locate a substring within a string up to a specified length.
 *
 * This function searches for the substring 'little' within the string 'big', 
 * up to the first 'len' characters or until the null terminator of 'big', 
 * whichever comes first. 
 * It returns a pointer to the first occurrence of 'little' within 'big'. 
 * If 'little' is an empty string, a pointer to 'big' is returned. If 'little' 
 * is not found within the specified range, NULL is returned.
 *
 * @param big A pointer to the string to be searched.
 * @param little A pointer to the substring to be located.
 * @param len The maximum number of characters to search within 'big'.
 * @return char* A pointer to the first occurrence of 'little' within 'big', 
 * or NULL if not found.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i_l;
	size_t	i_b;

	i_l = 0;
	i_b = 0;
	if (little[0] == 0)
		return ((char *) big);
	while (big[i_b])
	{
		i_l = 0;
		while (big[i_b + i_l] == little[i_l] && (i_b + i_l) < len)
		{
			if (big[i_b + i_l] == 0 && little[i_l] == 0)
				return ((char *) &big[i_b]);
			i_l++;
		}
		if (!little[i_l])
			return ((char *) &big[i_b]);
		i_b++;
	}
	return (0);
}
