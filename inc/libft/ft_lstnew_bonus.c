/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:27:03 by fsantama          #+#    #+#             */
/*   Updated: 2023/08/22 16:36:45 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Create a new element for a linked list.
 *
 * This function creates a new element for a linked list and initializes its 
 * 'content' and 'next' members. Memory is allocated for the new element, and 
 * the 'content' pointer is assigned to the provided 'content'. The 'next' 
 * pointer is initialized to NULL.
 *
 * @param content The content to be assigned to the new element.
 * @return t_list* A pointer to the new element, or NULL if allocation fails.
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*nodo;

	nodo = malloc(sizeof(t_list));
	if (!nodo)
		return (0);
	nodo->content = content;
	nodo->next = 0;
	return (nodo);
}
