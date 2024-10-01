/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:04:39 by fsantama          #+#    #+#             */
/*   Updated: 2023/08/22 15:54:55 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocate and zero-initialize memory.
 *
 * This function allocates a block of memory for an array of elements, each 
 * with a size of 'size' bytes. The total allocated memory size is determined 
 * by the product of 'count' and 'size'. The allocated memory block is then 
 * filled with zero bytes, effectively initializing it to zero.
 *
 * @param count The number of elements in the array.
 * @param size The size (in bytes) of each element.
 * @return void* A pointer to the allocated and initialized memory block,
 *         or NULL if allocation fails.
 */
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(size * count);
	if (ptr == 0)
		return (0);
	else
	{
		ft_bzero(ptr, (size * count));
		return (ptr);
	}
}
