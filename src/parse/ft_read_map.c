/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:24:31 by fsantama          #+#    #+#             */
/*   Updated: 2024/09/26 13:24:53 by fsantama         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../inc/cub3d.h"

/**
 * @brief Lee y procesa el mapa desde el archivo .cub
 * 
 * Esta función se encarga de leer el archivo línea por línea, omitiendo 
 * las líneas vacías y concatenando las líneas de mapa para su validación y normalización.
 * 
 * @param fd El descriptor de archivo del mapa
 * @param data La estructura principal del juego (t_data)
 */
void	ft_read_map(int fd, t_data *data)
{
	(void) data;
//	(void) fd;
	char	*line;

	printf("ft_read_map\n");

	line = get_next_line(fd);

	while (line)
	{
		printf("Prueba");
		printf("line: %s\n", line);
		ft_free_and_null((void **)&line);
		line = get_next_line(fd);
	}
	
//	line = ft_parse_identifiers(fd, data, get_next_line(fd));
	
	/*
	char	*line;
	char	*map;

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
//	map = ft_free_and_join(map, ft_strdup("\n "));
//	ft_check_map(map, data);
//	ft_normalize_map(map, data);
//	ft_free(map);
*/
}
