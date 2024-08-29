/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_and_join.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:44:34 by fsantama          #+#    #+#             */
/*   Updated: 2024/08/29 12:44:34 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

char *ft_free_and_join(char *s1, char *s2)
{
    char *new_str;
    
    if (!s1 || !s2)
        return NULL;
    new_str = ft_strjoin(s1, s2);  // Asegúrate de que ft_strjoin esté definida
    free(s1);  // Libera la primera cadena
    return new_str;
}