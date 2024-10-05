/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 10:33:24 by ajurado-          #+#    #+#             */
/*   Updated: 2024/10/05 10:33:24 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	init_colors(t_data	*data)
{
	data->color.white.r = 255;
	data->color.white.g = 255;
	data->color.white.b = 255;
	data->color.white.a = 255;
	data->color.gray.r = 125;
	data->color.gray.g = 125;
	data->color.gray.b = 125;
	data->color.gray.a = 255;
	data->color.golden.r = 212;
	data->color.golden.g = 175;
	data->color.golden.b = 55;
	data->color.golden.a = 255;
	data->color.blue.r = 27;
	data->color.blue.g = 32;
	data->color.blue.b = 73;
	data->color.blue.a = 255;
	data->color.green.r = 27;
	data->color.green.g = 114;
	data->color.green.b = 51;
	data->color.green.a = 255;
	data->color.red.r = 104;
	data->color.red.g = 0;
	data->color.red.b = 0;
	data->color.red.a = 255;
}

/**
 * @brief Inicializa las variables relacionadas con el estado del juego.
 *
 * Esta función inicializa variables como el estado de pausa, puertas,
 * interacción con el cursor y las dimensiones de la pantalla.
 *
 * @param data Estructura principal que contiene toda la información del juego.
 */
static void	init_game_state(t_data *data)
{
	data->screen_width = 0;
	data->screen_height = 0;
	data->pause = 0;
}

/**
 * @brief Inicializa las variables relacionadas con el mapa.
 *
 * Esta función inicializa las estructuras del mapa `map_close` y `map_open`,
 * poniendo los valores iniciales de las imágenes a NULL.
 *
 * @param data Estructura principal que contiene toda la información del juego.
 */
static void	init_map(t_data *data)
{
	data->map_close.img = NULL;
	data->map_open.img = NULL;
}

/**
 * @brief Inicializa los identificadores (iden) en la estructura principal.
 *
 * Esta función inicializa el array de identificadores `iden[]` a NULL,
 * asegurándose de que cada uno de estos punteros esté preparado antes
 * de ser usado para almacenar texturas u otros datos.
 *
 * @param data Estructura principal que contiene toda la información del juego.
 */
static void	init_iden(t_data *data)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		data->iden[i] = NULL;
		i++;
	}
}

/**
 * @brief Inicializa los valores de la estructura principal del juego.
 *
 * Esta función es responsable de llamar a subfunciones que inicializan
 * distintas partes de la estructura `t_data`, como los identificadores,
 * el mapa y los estados del juego. De esta manera, se asegura de que todos
 * los valores estén correctamente inicializados antes de comenzar el juego.
 *
 * @param data Estructura principal que contiene toda la información del juego.
 */
void	ft_init_data(t_data *data)
{
	init_iden(data);
	init_map(data);
	init_game_state(data);
	init_colors(data);
}
