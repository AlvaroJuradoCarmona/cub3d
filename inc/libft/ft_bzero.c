/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:00:26 by fsantama          #+#    #+#             */
/*   Updated: 2023/09/08 10:53:10 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Set a block of memory to zero.
 *
 * This function fills the first 'n' bytes of the memory pointed to by 's' with
 * zero bytes. It effectively clears the memory, making it all zeros.
 *
 * @param s A pointer to the start of the memory block.
 * @param n The number of bytes to set to zero.
 */
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
