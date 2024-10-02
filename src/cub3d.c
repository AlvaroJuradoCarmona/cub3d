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

/**
 * @brief Verifica los argumentos pasados al programa.
 *
 * Esta función comprueba que el número de argumentos pasados al programa es el correcto.
 * En este caso, se espera que el número de argumentos sea 2, lo que implica que el 
 * programa ha sido llamado con un único archivo de mapa. Si la verificación falla, 
 * se muestra un mensaje de error utilizando `ft_error`.
 *
 * @param argc El número de argumentos pasados al programa.
 * @param argv El array de strings con los argumentos pasados al programa.
 *
 * @note Si `argc` no es igual a 2 o `argv[1]` es NULL, se llama a `ft_error` para 
 *       mostrar el mensaje de error y terminar la ejecución del programa.
 */static void	check_arguments(int argc, char **argv)
{
	if (argc != 2 || !argv[1])
		ft_error(INVALID_ARGC, 0);
}

// Función para inicializar el motor gráfico y configuraciones de MLX
static void	setup_mlx(t_data *data)
{
	ft_init_images(data);
	ft_map_construct(data);
	/*
	mlx_loop_hook(data->mlx, &ft_keyboard_hooks, (void *)data);
	mlx_loop_hook(data->mlx, &ft_time_hook, (void *)data);
	mlx_cursor_hook(data->mlx, &ft_cursor_hook, (void *)data);
	mlx_loop(data->mlx);
	*/
}

/**
 * @brief Punto de entrada principal del programa.
 *
 * Inicializa el programa, verifica los argumentos, carga los datos del juego y 
 * eventualmente configura la ventana gráfica utilizando la biblioteca MLX42.
 * 
 * @param argc Número de argumentos pasados al programa.
 * @param argv Array de cadenas de texto que contiene los argumentos del programa.
 * 
 * @return Devuelve `EXIT_SUCCESS` en caso de que el programa se ejecute correctamente.
 *         En caso de error, se gestionan mediante llamadas a `ft_error` que terminarán el programa.
 * 
 * @note La función realiza las siguientes tareas:
 *       - Imprime el encabezado del juego.
 *       - Verifica los argumentos de entrada.
 *       - Inicializa los datos del juego.
 *       - Carga los datos del mapa y otros elementos del juego.
 */
int main(int argc, char **argv)
{
    t_data  data;

	check_arguments(argc, argv);
	ft_init_data(&data);
	ft_parse_data(argv[1], &data);
	setup_mlx(&data);
	//ft_final_cleaner(&data); // Asume que hay que limpiar al final del programa
	
    return (EXIT_SUCCESS);
}


