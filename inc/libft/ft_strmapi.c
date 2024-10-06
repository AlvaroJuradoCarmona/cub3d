/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:15:23 by fsantama          #+#    #+#             */
/*   Updated: 2023/08/22 18:45:20 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Apply a function to each character of a string with its index and 
 * create a new string.
 * This function applies the function 'f' to each character of the string 's' 
 * along with its index.
 * It creates a new string with the transformed characters and returns a 
 * pointer to the new string.
 * Memory is allocated for the new string. If memory allocation fails, NULL is 
 * returned.
 *
 * @param s A pointer to the string to be iterated over.
 * @param f A pointer to the function to be applied to each character.
 * @return char* A pointer to the new string with transformed characters, or 
 * NULL if allocation fails.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			len;
	char			*str;

	i = 0;
	len = ft_strlen(s);
	str = (char *) malloc (sizeof (char) * (len +1));
	if (!s || !f)
		return (0);
	if (!str)
		return (0);
	while (i < len)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}
