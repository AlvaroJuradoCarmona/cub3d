/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:46:43 by fsantama          #+#    #+#             */
/*   Updated: 2023/08/22 18:44:19 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Calculate the length of a null-terminated string.
 *
 * This function calculates the length of the null-terminated string 's'
 * by iterating through its characters until the null terminator is reached.
 *
 * @param s A pointer to the null-terminated string.
 * @return size_t The length of the string.
 */
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
			i++;
	return (i);
}
