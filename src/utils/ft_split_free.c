/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 09:07:09 by fsantama          #+#    #+#             */
/*   Updated: 2024/09/02 09:07:09 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	ft_split_free(char **str)
{
	char	**ptr;

	if (str == NULL)
		return ;
	ptr = str;
	while (*ptr != NULL)
	{
		ft_free_and_null((void **)&*ptr);
		ptr++;
	}
	ft_free_and_null((void **)&str);
}
