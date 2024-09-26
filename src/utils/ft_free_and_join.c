/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_and_join.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:44:34 by fsantama          #+#    #+#             */
/*   Updated: 2024/09/26 10:49:39 by fsantama         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../inc/cub3d.h"

void	ft_multiple_free(int num_args, ...)
{
	va_list	args;
	void	*ptr;
	int		i;

	i = -1;
	va_start(args, num_args);
	while (++i < num_args)
	{
		ptr = va_arg(args, void *);
		ft_free_and_null((void **)&ptr);
	}
	va_end(args);
}

char *ft_free_and_join(char *s1, char *s2)
{
	char	*strjoin;

	strjoin = ft_strjoin(s1, s2);
	ft_multiple_free(2, s1, s2);
	return (strjoin);
}

