/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:35:52 by fsantama          #+#    #+#             */
/*   Updated: 2023/08/22 16:30:30 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Delete a single element from a linked list.
 *
 * This function deletes a single element 'lst' from the linked list by 
 * freeing the memory associated with its content and the element itself. 
 * The provided 'del' function is responsible for freeing the memory of the 
 * content.
 *
 * @param lst The element to be deleted.
 * @param del A pointer to a function that takes a data element and deletes it.
 *            It's responsible for freeing the memory associated with the 
 * 			  element.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst)
	{
		del(lst -> content);
		free(lst);
	}
}
