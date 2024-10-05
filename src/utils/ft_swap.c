/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 10:37:12 by ajurado-          #+#    #+#             */
/*   Updated: 2024/10/05 10:37:23 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	*ft_swap_aux(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)dst)[i] = ((const char *)src)[i];
		i++;
	}
	return (dst);
}

void	ft_swap(void *a, void *b, size_t size)
{
	char	*tmp;

	tmp = ft_calloc(size, sizeof(char));
	ft_swap_aux(tmp, a, size);
	ft_swap_aux(a, b, size);
	ft_swap_aux(b, tmp, size);
	ft_free_and_null((void **)&tmp);
}
