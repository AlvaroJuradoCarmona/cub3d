/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:45:41 by fsantama          #+#    #+#             */
/*   Updated: 2023/08/22 16:34:09 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Get the last element of a linked list.
 *
 * This function returns a pointer to the last element of the linked list 
 * 'lst'. It traverses the list from the head until it reaches the last element 
 * and then returns a pointer to that last element.
 *
 * @param lst The head of the linked list.
 * @return t_list* A pointer to the last element of the list, or NULL if the 
 * list is empty.
 */
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*aux;

	if (!lst)
		return (0);
	aux = lst;
	while (aux->next)
		aux = aux->next;
	return (aux);
}
