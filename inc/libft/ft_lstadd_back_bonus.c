/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:32:56 by fsantama          #+#    #+#             */
/*   Updated: 2023/08/22 16:27:38 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Add a new element to the end of a linked list.
 *
 * This function adds a new element 'new' to the end of the linked list 'lst'.
 * If the list is initially empty (*lst is NULL), 'new' becomes the first 
 * element.
 *
 * @param lst A pointer to a pointer to the head of the linked list.
 * @param new The element to be added to the end of the list.
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*aux;

	aux = ft_lstlast(*lst);
	if (aux)
		aux -> next = new;
	else
		*lst = new;
}
