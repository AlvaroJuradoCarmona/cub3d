/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:05:38 by fsantama          #+#    #+#             */
/*   Updated: 2023/08/22 16:26:27 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Check if a character is a digit.
 *
 * This function determines whether the given character 'c' is a digit 
 * character. Digit characters are those with values between '0' and '9' 
 * (inclusive).
 *
 * @param c The character to be checked.
 * @return int Returns 1 if the character is a digit, and 0 otherwise.
 */
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
