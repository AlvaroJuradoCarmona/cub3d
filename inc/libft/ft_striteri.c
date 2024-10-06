/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:16:54 by fsantama          #+#    #+#             */
/*   Updated: 2023/08/22 18:17:49 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Apply a function to each character of a string with its index.
 *
 * This function applies the function 'f' to each character of the string 's'
 * along with its index. The index starts from 0 and increases with each 
 * character.
 * The null terminator of the string is also set to 0 after applying the 
 * function.
 *
 * @param s A pointer to the string to be iterated over.
 * @param f A pointer to the function to be applied to each character.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;
	size_t			len;

	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		f(i, &s[i]);
		i++;
	}
	s[i] = 0;
}
