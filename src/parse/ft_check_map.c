/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:29:07 by fsantama          #+#    #+#             */
/*   Updated: 2024/08/29 12:29:07 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * @brief Valida si un carácter es inválido en el mapa
 * 
 * Esta función revisa si un carácter dentro del mapa es válido, es decir,
 * si es uno de los caracteres permitidos ('0', '1', '2', espacio, etc.).
 * 
 * @param c El carácter a validar
 * @return true si es inválido, false si es válido
 */
bool	ft_is_invalid_value(char c)
{
	return (c != '0' && c != '1' && c != ' ' && c != '2');
}

/**
 * @brief Verifica si el mapa tiene un formato válido
 * 
 * Esta función recorre el mapa para verificar que cumpla con los 
 * requisitos esenciales: debe contener exactamente un punto de inicio
 * del jugador ('N', 'S', 'W' o 'E'). También asegura que las dimensiones del 
 * mapa sean correctas.
 * 
 * @param map El contenido del mapa en una cadena
 * @param data La estructura principal del juego (t_data)
 */
void	ft_check_map(char *map, t_data *data)
{
	t_coords	p;
	short int	flag[2];

	p.x = -1;
	p.y = 0;
	flag[0] = 0;
	flag[1] = 0;
	while (map[++p.x] && flag[0] < 2 && flag[1] < 2)
	{
		if (map[p.x] == 'N' || map[p.x] == 'S' || \
			map[p.x] == 'W' || map[p.x] == 'E')
			flag[0]++;
		else if (map[p.x] == '\n')
		{
			if (p.x - p.y + 1 > data->map_width)
				data->map_width = p.x - p.y + 1;
			p.y = p.x;
		}
		else if (ft_is_invalid_value(map[p.x]))
			flag[0] = 2;
	}
	if (flag[0] != 1 || flag[1] > 1)
		ft_error("Error: Invalid map configuration.", 0);
}
