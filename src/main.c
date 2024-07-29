/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 08:57:54 by fsantama          #+#    #+#             */
/*   Updated: 2024/07/24 08:57:54 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

t_mlx_errno g_mlx_errno;

int main(int argc, char **argv)
{
    t_data  data;

    // ft_printf("%s", &(HEADER)); IMPRIMIR HEADER CUANDO LO HAGA
    if (argc == 2 && argv[1])
	{
        ft_init_data(&data);
		return (EXIT_SUCCESS);
	}
	else
	{
	//	ft_error(data, INVALID_ARGC);
		return (EXIT_FAILURE);
	}
}

