/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 12:30:53 by fsantama          #+#    #+#             */
/*   Updated: 2024/08/05 12:30:53 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/* 
static void	ft_readmap(int fd, t_data *data)
{
//	char *line;
	(void) fd;

//	line = get_next_line(fd);
}
*/

void	ft_parse_data(char *file, t_data *data)
{
    int		fd;
	size_t	len;

	data->screen_width = 0; // PARA QUE NO DE ERROR DE MOMENTO
	len = strlen(file);
	if (len < 5 || strcmp(file + len - 4, ".cub") != 0)
		ft_error("Error\nInvalid extension.", 0);
		//ft_putendl_fd(EXTENSION_ERR, STDERR_FILENO); ESTO NO LO ENTIENDO
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error("Error\nCould not read the file\n", 0);
		//ft_putendl_fd(FILE_ERR, STDERR_FILENO); ESTO NO LO ENTIENDO
	//ft_readmap(fd, data);
	close(fd);
	//ft_map_parse(data);
}