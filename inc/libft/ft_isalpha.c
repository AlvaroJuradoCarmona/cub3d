/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:52:55 by fsantama          #+#    #+#             */
/*   Updated: 2023/08/22 15:57:08 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Check if a character is an alphabetic character.
 *
 * This function determines whether the given character 'c' is an alphabetic 
 * character. An alphabetic character is either an uppercase letter or a 
 * lowercase letter.
 *
 * @param c The character to be checked.
 * @return int Returns 1 if the character is alphabetic, and 0 otherwise.
 */
int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
