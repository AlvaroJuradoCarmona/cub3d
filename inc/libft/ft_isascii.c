/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:26:13 by fsantama          #+#    #+#             */
/*   Updated: 2023/08/22 15:58:16 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Check if a character is a valid ASCII character.
 *
 * This function determines whether the given character 'c' is a valid ASCII 
 * character. ASCII characters have integer values in the range of 0 to 127 
 * (inclusive).
 *
 * @param c The character to be checked.
 * @return int Returns 1 if the character is a valid ASCII character, and 0 
 * 		   otherwise.
 */
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
