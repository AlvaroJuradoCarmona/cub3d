/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:31:25 by fsantama          #+#    #+#             */
/*   Updated: 2023/09/08 10:53:14 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Convert a string to an integer.
 *
 * This function converts the provided null-terminated string into an integer 
 * value. It skips leading whitespace characters and handles both positive and 
 * negative sign symbols. The string must represent a valid integer for 
 * accurate conversion.
 *
 * @param str The null-terminated string to be converted to an integer.
 * @return int The integer value extracted from the input string.
 */
int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	b;

	i = 0;
	sign = 1;
	b = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == 32)
		i++;
	if (str[i] == 45)
		sign *= -1;
	if (str[i] == 43 || sign == -1)
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		b = (str[i] - '0') + (b * 10);
		i++;
	}
	return (sign * b);
}
