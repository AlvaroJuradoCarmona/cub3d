/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_normalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:30:45 by fsantama          #+#    #+#             */
/*   Updated: 2024/08/29 12:30:45 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * @brief Ajusta el tamaño de cada fila del mapa para que todas tengan el mismo 
 * ancho
 * 
 * Esta función normaliza el mapa agregando espacios en blanco al final de cada
 * fila que no cumpla con el ancho máximo. Así, se asegura que todas las filas 
 * tengan la misma longitud, lo cual es necesario para la correcta 
 * representación del mapa en el juego.
 * 
 * @param map El contenido del mapa en una cadena
 * @param data La estructura principal del juego (t_data)
 */
void	ft_normalize_map(char *map, t_data *data)
{
	int		i;
	int		j;
	char	*row;

	data->map = ft_split(map, '\n');
	data->map_height = ft_split_size(data->map);
	i = 0;
	while (data->map[i])
	{
		row = ft_calloc(data->map_width + 1, sizeof(char));
		row[0] = ' ';
		ft_strlcpy(&row[1], data->map[i], data->map_width);
		j = ft_strlen(data->map[i]);
		while (++j < data->map_width)
			row[j] = ' ';
		ft_free_and_null((void **)&data->map[i]);
		data->map[i] = row;
		i++;
	}
}
