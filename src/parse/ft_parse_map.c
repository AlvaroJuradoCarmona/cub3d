/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 09:26:28 by fsantama          #+#    #+#             */
/*   Updated: 2024/10/01 09:55:29 by fsantama         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../inc/cub3d.h"

/**
 * @brief Valida si los espacios vacíos en el mapa están correctamente rodeados por paredes.
 * 
 * Esta función revisa en una dirección (vertical u horizontal) desde una posición específica
 * en el mapa si el espacio vacío (' ') está rodeado por paredes ('1'). Si encuentra cualquier
 * otro carácter que no sea una pared, la validación falla.
 *
 * @param data La estructura principal de datos del juego que contiene el mapa.
 * @param i Coordenada Y de la posición en el mapa.
 * @param j Coordenada X de la posición en el mapa.
 * @param direction La dirección a verificar: 0 para vertical (revisar filas), 1 para horizontal (revisar columnas).
 * @return int 1 si hay un error en la validación (no rodeado por paredes), 0 si es válido.
 */
static int ft_check_surroundings(t_data data, int i, int j, int direction)
{
    int step = (direction == 0) ? 1 : -1;
    int limit = (direction == 0) ? data.map_height : data.map_width;

    while ((direction == 0 && (i >= 0 && i < limit)) || (direction == 1 && (j >= 0 && j < limit)))
    {
        if (i < 0 || j < 0 || i >= data.map_height || j >= data.map_width || data.map[i][j] == '\0')
            return (1);

        if (data.map[i][j] != ' ')
        {
            if (data.map[i][j] == '1') break;
            return (1);
        }
        i += (direction == 0) ? step : 0;
        j += (direction == 1) ? step : 0;
    }
    return (0);
}

/**
 * @brief Valida el mapa completo para asegurarse de que los espacios vacíos estén rodeados por paredes.
 * 
 * Esta función recorre cada celda del mapa y, si encuentra un espacio vacío (' '),
 * llama a `ft_check_surroundings` para verificar que esté rodeado por paredes.
 *
 * @param data La estructura principal de datos del juego que contiene el mapa.
 * @return int 1 si el mapa es inválido, 0 si el mapa es válido.
 */
static int ft_validate_map(t_data data)
{
    int i, j;
    
    i = -1;
    while (++i < data.map_height)
    {
        j = -1;
        while (++j < data.map_width)
        {
            if (data.map[i][j] == ' ')
            {
                if (ft_check_surroundings(data, i, j, 0) || ft_check_surroundings(data, i, j, 1))
                    return (1);
            }
        }
    }
    return (0);
}

/**
 * @brief Extrae la posición inicial del jugador del mapa.
 * 
 * Esta función busca en el mapa la posición del jugador representada por una de las letras
 * ('N', 'S', 'W', 'E'). Si encuentra la posición, actualiza las coordenadas y el ángulo de
 * rotación del jugador en la estructura `data`. El ángulo de rotación se establece según la
 * dirección en la que el jugador está mirando.
 *
 * @param data La estructura principal del juego donde se actualizará la posición del jugador.
 * @return int 1 si la posición del jugador fue encontrada, 0 si no se encontró.
 */
static int ft_set_player_position(t_data *data)
{
    t_coords p;

    p.y = -1;
    while (data->map[++p.y])
    {
        p.x = -1;
        while (data->map[p.y][++p.x])
        {
            char pos = data->map[p.y][p.x];
            if (pos == 'N' || pos == 'S' || pos == 'W' || pos == 'E')
            {
                data->player.pos.x = p.x * BLOCKSIZE + BLOCKSIZE / 2;
                data->player.pos.y = p.y * BLOCKSIZE + BLOCKSIZE / 2;
                data->player.angle = (pos == 'N') ? 90 * TORADIANS :
                                     (pos == 'S') ? 270 * TORADIANS :
                                     (pos == 'W') ? 180 * TORADIANS : 0;
                return (1);
            }
        }
    }
    return (0);
}

/**
 * @brief Función principal para parsear, validar y extraer datos del mapa.
 * 
 * Esta función ejecuta el proceso completo de validación y parseo del mapa.
 * Primero, valida el mapa para asegurarse de que los espacios vacíos estén rodeados por paredes.
 * Luego, extrae la posición inicial del jugador y la establece en la estructura `data`.
 * Si alguna de las validaciones falla, se limpia la memoria y se imprime un mensaje de error.
 *
 * @param data La estructura principal del juego que contiene toda la información del mapa y del jugador.
 */
 void ft_parse_map(t_data *data)
{
    if (ft_validate_map(*data))
    {
        ft_initial_cleaner(data);
        ft_error("ERROR: Mapa no válido", 0);
    }
    if (!ft_set_player_position(data))
    {
        ft_initial_cleaner(data);
        ft_error("ERROR: No se encontró la posición del jugador", 0);
    }
}
