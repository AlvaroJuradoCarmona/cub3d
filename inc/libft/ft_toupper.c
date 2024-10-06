/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:40:25 by fsantama          #+#    #+#             */
/*   Updated: 2023/08/22 18:51:36 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Convert a lowercase character to uppercase.
 *
 * This function converts the lowercase character 'c' to its corresponding 
 * uppercase character.
 * If 'c' is not a lowercase character, it remains unchanged. The function 
 * returns the uppercase version of 'c'.
 *
 * @param c The character to be converted to uppercase.
 * @return int The uppercase version of the character 'c'.
 */
int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c = c - 32;
	return (c);
}
