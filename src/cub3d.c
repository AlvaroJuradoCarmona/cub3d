/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:26:54 by fsantama          #+#    #+#             */
/*   Updated: 2024/10/02 10:22:22 by fsantama         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../inc/cub3d.h"

void	ft_final_cleaner(t_data *data)
{
	ft_initial_cleaner(data);
	mlx_delete_image(data->mlx, data->player.img);
	mlx_delete_image(data->mlx, data->galaxy_i);
	mlx_delete_image(data->mlx, data->player.ray_img);
	mlx_delete_image(data->mlx, data->wall.n);
	mlx_delete_image(data->mlx, data->wall.s);
	mlx_delete_image(data->mlx, data->wall.w);
	mlx_delete_image(data->mlx, data->wall.e);
	mlx_terminate(data->mlx);
}

static void	check_arguments(int argc, char **argv)
{
	if (argc != 2 || !argv[1])
		ft_error(INVALID_ARGC, 0);
}

static void	setup_mlx(t_data *data)
{
	ft_init_images(data);
	ft_map_construct(data);
	mlx_loop_hook(data->mlx, &ft_keyboard_hooks, (void *)data);
	mlx_cursor_hook(data->mlx, &ft_cursor_hook, (void *)data);
	mlx_loop(data->mlx);
}

int main(int argc, char **argv)
{
    t_data  data;

	check_arguments(argc, argv);
	ft_init_data(&data);
	ft_parse_data(argv[1], &data);
	setup_mlx(&data);
	ft_final_cleaner(&data); // Asume que hay que limpiar al final del programa
	
    return (EXIT_SUCCESS);
}


