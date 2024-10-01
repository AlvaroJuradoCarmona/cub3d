/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:11:48 by fsantama          #+#    #+#             */
/*   Updated: 2023/08/22 15:56:24 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Check if a character is alphanumeric.
 *
 * This function checks whether the given character 'c' is an alphanumeric 
 * character.An alphanumeric character is either an uppercase letter, a 
 * lowercase letter, or a digit.
 *
 * @param c The character to be checked.
 * @return int Returns 1 if the character is alphanumeric, and 0 otherwise.
 */
int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
