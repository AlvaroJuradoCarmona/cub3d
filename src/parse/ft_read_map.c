/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 10:57:59 by ajurado-          #+#    #+#             */
/*   Updated: 2024/10/05 10:57:59 by ajurado-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * @brief Lee y procesa el mapa desde el archivo .cub
 * 
 * Esta función se encarga de leer el archivo línea por línea, omitiendo 
 * las líneas vacías y concatenando las líneas de mapa para su validación y 
 * normalización.
 * 
 * @param fd El descriptor de archivo del mapa
 * @param data La estructura principal del juego (t_data)
 */
void	ft_read_map(int fd, t_data *data)
{
	char	*line;
	char	*map;

	line = ft_parse_identifiers(fd, data, get_next_line(fd));
	while (line && line[0] == '\n')
	{
		ft_free_and_null((void **)&line);
		line = get_next_line(fd);
	}
	if (!line)
		ft_error("Error: File doesn't contain a valid map.", 0);
	map = ft_strdup(" \n");
	while (line)
	{
		if (line[0] == '\n')
			break ;
		map = ft_free_and_join(map, line);
		line = get_next_line(fd);
	}
	map = ft_free_and_join(map, ft_strdup("\n "));
	ft_check_map(map, data);
	ft_normalize_map(map, data);
	ft_free(map);
	ft_free(line);
}
