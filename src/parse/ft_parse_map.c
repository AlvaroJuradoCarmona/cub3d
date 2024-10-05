/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 10:58:27 by ajurado-          #+#    #+#             */
/*   Updated: 2024/10/05 10:58:27 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * @brief Valida si los espacios vacíos en el mapa están correctamente rodeados 
 * por paredes.
 * 
 * Esta función revisa en una dirección (vertical u horizontal) desde una 
 * posición específica en el mapa si el espacio vacío (' ') está rodeado por 
 * paredes ('1'). Si encuentra cualquier otro carácter que no sea una pared, 
 * la validación falla.
 *
 * @param data La estructura principal de datos del juego que contiene el mapa.
 * @param i Coordenada Y de la posición en el mapa.
 * @param j Coordenada X de la posición en el mapa.
 * @param direction La dirección a verificar: 0 para vertical (revisar filas), 
 * 1 para horizontal (revisar columnas).
 * @return int 1 si hay un error en la validación (no rodeado por paredes), 
 * 0 si es válido.
 */
static int	ft_check_surroundings(t_data data, int i, int j, int direction)
{
	int	step;
	int	limit;

	step = (direction == 0) ? 1 : -1;
	limit = (direction == 0) ? data.map_height : data.map_width;
	while ((direction == 0 && (i >= 0 && i < limit)) || (direction == 1 && (j >= 0 && j < limit)))
	{
		if (i < 0 || j < 0 || i >= data.map_height || j >= data.map_width || data.map[i][j] == '\0')
			return (1);
		if (data.map[i][j] != ' ')
		{
			if (data.map[i][j] == '1')
				break;
			return (1);
		}
		i += (direction == 0) ? step : 0;
		j += (direction == 1) ? step : 0;
	}
	return (0);
}

static int	ft_validate_map(t_data data)
{
	int i;
	int j;

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

static int	ft_set_player_position(t_data *data)
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

void	ft_parse_map(t_data *data)
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
