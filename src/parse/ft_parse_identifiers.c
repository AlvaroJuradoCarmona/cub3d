/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_identifiers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:38:25 by fsantama          #+#    #+#             */
/*   Updated: 2024/09/27 10:28:28 by fsantama         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../inc/cub3d.h"

/**
 * @brief Extrae el color a partir de una cadena de texto en formato "R,G,B".
 * Verifica si los valores de color están entre 0 y 255.
 * 
 * @param color_str Cadena con el formato "R,G,B".
 * @param color Estructura que almacenará los valores de color.
 * @return true Si la extracción fue exitosa.
 * @return false Si hubo algún error en el formato o valores inválidos.
 */
static bool ft_extract_color(char *color_str, t_pixels *color)
{
    char **aux;
    int i;

    aux = ft_split(color_str, ',');  // Divide la cadena de texto por comas
    if (!aux || ft_split_size(aux) != 3) // Verifica que tiene 3 valores (R, G, B)
        return (ft_split_free(aux), 0);  // Libera la memoria si el formato no es válido

    i = 0;
    // Verifica si los valores son válidos (números entre 0 y 255)
    while (i < 3)
    {
        if (!ft_isdigit(aux[i][0]) || ft_atoi(aux[i]) < 0 || ft_atoi(aux[i]) > 255)
        {
            ft_split_free(aux);  // Libera la memoria en caso de error
            return (0);          // Devuelve falso si algún valor es inválido
        }
        i++;
    }
    // Asigna los valores de color extraídos
    color->r = ft_atoi(aux[0]);
    color->g = ft_atoi(aux[1]);
    color->b = ft_atoi(aux[2]);
    color->a = 255;  // Color completamente opaco (alfa = 255)
    ft_split_free(aux);  // Libera la memoria después de su uso
    return (1);  // Éxito
}

/**
 * @brief Encuentra el identificador (NO, SO, WE, EA, F, C) en una línea.
 * Verifica que no haya duplicados y devuelve el índice correspondiente al identificador.
 * 
 * @param line Línea de texto que contiene el identificador.
 * @param data Estructura principal que contiene los identificadores.
 * @param j Índice en la línea donde comienza la búsqueda del identificador.
 * @return int Índice del identificador (0-5) o -1 en caso de error.
 */
static int ft_find_identifier(char *line, t_data *data, int *j)
{
	*j = 0;
	while (line[*j] == ' ')
		(*j)++;
	if (line[0] == '\n')
		return (-1);
	else if (ft_strncmp("NO ", &line[*j], 3) == 0 && !data->iden[0])
		return (0);
	else if (ft_strncmp("SO ", &line[*j], 3) == 0 && !data->iden[1])
		return (1);
	else if (ft_strncmp("WE ", &line[*j], 3) == 0 && !data->iden[2])
		return (2);
	else if (ft_strncmp("EA ", &line[*j], 3) == 0 && !data->iden[3])
		return (3);
	else if (ft_strncmp("F ", &line[*j], 2) == 0 && !data->iden[4])
		return (4);
	else if (ft_strncmp("C ", &line[*j], 2) == 0 && !data->iden[5])
		return (5);
    ft_error("Error: Duplicated or malformed identifier.", 0);
    return (-2);  // Error
}

/**
 * @brief Procesa los identificadores del archivo (NO, SO, WE, EA, F, C)
 * y extrae las rutas de texturas o los valores de colores del suelo/techo.
 * 
 * @param fd Descriptor del archivo de mapa.
 * @param data Estructura principal que almacena los datos del mapa.
 * @param line Línea de texto actual del archivo.
 * @return char* La siguiente línea después de procesar los identificadores.
 */
char *ft_parse_identifiers(int fd, t_data *data, char *line)
{
	int		pos;
	int		i;
	int		j;

	i = 0;
	while (line && i < 6)
	{
		pos = ft_find_identifier(line, data, &j);
		if (pos >= 0 && pos <= 5)
		{
			j += 2;
			while (line[j] == ' ')
				j++;
			data->iden[pos] = ft_substr(line + j, 0, ft_strlen(line + j) - 1);
			i++;
		}
		ft_free_and_null((void **)&line);
		line = get_next_line(fd);
	}
    if (!line || !ft_extract_color(data->iden[4], &data->map_open.floor_color) || \
        !ft_extract_color(data->iden[5], &data->map_open.ceiling_color))
        ft_error("Error: Invalid map or color data.", 0);
    return line;
}
