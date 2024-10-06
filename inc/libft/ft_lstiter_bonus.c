/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:38:59 by fsantama          #+#    #+#             */
/*   Updated: 2023/08/22 16:31:30 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Apply a function to each element of a linked list.
 *
 * This function applies the function 'f' to each element of the linked list 
 * 'lst'. The function 'f' is applied to the content of each element, and the 
 * traversal continues until the end of the list is reached.
 *
 * @param lst The head of the linked list.
 * @param f A pointer to a function to be applied to each element's content.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst)
	{
		while (lst)
		{
			f(lst->content);
			lst = lst->next;
		}
	}
}
