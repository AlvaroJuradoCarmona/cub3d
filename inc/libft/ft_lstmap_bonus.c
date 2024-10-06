/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:40:24 by fsantama          #+#    #+#             */
/*   Updated: 2023/08/22 16:35:52 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Create a new linked list by applying a function to each element.
 *
 * This function creates a new linked list by applying the function 'f' to each 
 * element of the input linked list 'lst'. It allocates memory for each new 
 * element and its content, and the 'del' function is used to free memory in 
 * case of allocation failure. The newly created linked list is returned, or 
 * NULL if any allocation fails.
 *
 * @param lst The input linked list to be processed.
 * @param f A pointer to a function that takes an element's content and 
 * 			returns a new content to be assigned to the corresponding element 
 * 			in the new list.
 * @param del A pointer to a function that takes an element's content and 
 * 			  deletes it. It's used to free memory in case of allocation 
 * 			  failure.
 * @return t_list* A pointer to the new linked list, or NULL if allocation 
 * 		   fails.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst2;
	t_list	*aux;

	lst2 = 0;
	while (lst)
	{
		aux = ft_lstnew(f(lst->content));
		if (!lst)
		{
			ft_lstclear(&lst, del);
			return (0);
		}
		ft_lstadd_back(&lst2, aux);
		lst = lst->next;
	}
	return (lst2);
}
