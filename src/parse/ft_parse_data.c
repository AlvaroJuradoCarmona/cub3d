/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 12:30:53 by fsantama          #+#    #+#             */
/*   Updated: 2024/10/01 09:10:23 by fsantama         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../inc/cub3d.h"

/**
 * @brief Función principal que inicia el parsing del archivo .cub
 * 
 * Esta función se encarga de validar el nombre del archivo, abrirlo y 
 * delegar el trabajo de parsing a las funciones correspondientes. 
 * Valida que el archivo tenga la extensión correcta (.cub) y luego 
 * procede a leer el contenido del archivo.
 * 
 * @param file El nombre del archivo .cub a procesar
 * @param data La estructura principal del juego (t_data)
 */
void	ft_parse_data(char *file, t_data *data)
{
	int		fd;
	int		file_len;
	
	file_len = 0;
	while (file[file_len])
		file_len++;
	if (file_len < 5 || ft_strncmp(".cub", &file[file_len - 4], 4) != 0)
		ft_error("Error: Invalid file extension. Expected .cub", 0);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error("Error: Could not open the file.", 0);
	ft_read_map(fd, data);
	close(fd);
	ft_parse_map(data);
}
