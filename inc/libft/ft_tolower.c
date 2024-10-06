/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:46:12 by fsantama          #+#    #+#             */
/*   Updated: 2023/09/08 10:57:40 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Convert an uppercase character to lowercase.
 *
 * This function converts the uppercase character 'c' to its corresponding 
 * lowercase character.
 * If 'c' is not an uppercase character, it remains unchanged. The function 
 * returns the lowercase version of 'c'.
 *
 * @param c The character to be converted to lowercase.
 * @return int The lowercase version of the character 'c'.
 */
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
