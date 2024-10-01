/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 09:25:04 by fsantama          #+#    #+#             */
/*   Updated: 2024/10/01 10:12:17 by fsantama         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../inc/cub3d.h"

/**
 * @brief Inicializa las variables relacionadas con el mapa.
 *
 * Esta función inicializa las estructuras del mapa `map_close` y `map_open`,
 * poniendo los valores iniciales de las imágenes a NULL.
 *
 * @param data Estructura principal que contiene toda la información del juego.
 */
static void init_map(t_data *data)
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
static void init_iden(t_data *data)
{
    int i = 0;
    while (i < 6)
    {
        data->iden[i] = NULL;
        i++;
    }
}

/**
 * @brief Inicializa las variables relacionadas con el estado del juego.
 *
 * Esta función inicializa variables como el estado de pausa, puertas,
 * interacción con el cursor y las dimensiones de la pantalla.
 *
 * @param data Estructura principal que contiene toda la información del juego.
 */
static void init_game_state(t_data *data)
{
    data->screen_width = 0;
    data->screen_height = 0;
    data->pause = false;
    data->door_open = false;
    data->pass_door = false;
    data->cursor_hook = false;
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
void ft_init_data(t_data *data)
{
    init_iden(data);
    init_map(data);
    init_game_state(data);
    // init_colors(data); // Cuando metamos colores
}
