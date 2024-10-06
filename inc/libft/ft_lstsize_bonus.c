/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:29:45 by fsantama          #+#    #+#             */
/*   Updated: 2023/08/22 16:37:22 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Calculate the number of elements in a linked list.
 *
 * This function calculates and returns the number of elements in the linked 
 * list 'lst'.
 *
 * @param lst The head of the linked list.
 * @return int The number of elements in the list.
 */
int	ft_lstsize(t_list *lst)
{
	t_list	*aux;
	int		counter;

	counter = 0;
	if (!lst)
		return (0);
	aux = lst;
	while (aux)
	{
		aux = aux->next;
		counter++;
	}
	return (counter);
}
