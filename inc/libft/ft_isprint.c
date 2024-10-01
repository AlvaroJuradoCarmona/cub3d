/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:41:40 by fsantama          #+#    #+#             */
/*   Updated: 2023/09/08 10:54:36 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Check if a character is a printable character.
 *
 * This function determines whether the given character 'c' is a printable 
 * character. Printable characters are those with ASCII values in the range 
 * of 32 to 126 (inclusive).
 *
 * @param c The character to be checked.
 * @return int Returns 1 if the character is printable, and 0 otherwise.
 */
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
