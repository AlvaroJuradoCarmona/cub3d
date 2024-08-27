/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:26:54 by fsantama          #+#    #+#             */
/*   Updated: 2024/07/31 13:26:54 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// Función para verificar los argumentos
static void	check_arguments(int argc, char **argv)
{
	if (argc != 2 || !argv[1])
		ft_error(INVALID_ARGC, 0);
}
/*
// Función para inicializar el motor gráfico y configuraciones de MLX
static void	setup_mlx(t_data *data)
{
	init_images(data);
	map_construct(data);
	mlx_loop_hook(data->mlx, &ft_keyboard_hooks, (void *)data);
	mlx_loop_hook(data->mlx, &ft_time_hook, (void *)data);
	mlx_cursor_hook(data->mlx, &ft_cursor_hook, (void *)data);
	mlx_loop(data->mlx);
}
*/

int main(int argc, char **argv)
{
    t_data  data;

	// ft_printf("%s", &(HEADER)); // Imprimir header cuando esté implementado
	check_arguments(argc, argv);
	ft_init_data(&data);
	ft_parse_data(argv[1], &data);
	//setup_mlx(&data);
	//ft_final_cleaner(&data); // Asume que hay que limpiar al final del programa
	
    return (EXIT_SUCCESS);
}


