/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_and_join.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 10:46:03 by ajurado-          #+#    #+#             */
/*   Updated: 2024/10/05 10:46:03 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

char	*ft_free_and_join(char *s1, char *s2)
{
	char	*strjoin;

	strjoin = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (strjoin);
}
