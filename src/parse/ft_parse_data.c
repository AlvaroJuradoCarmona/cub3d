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

void	ft_parse_data(char *file, t_data *data)
{
    int		fd = 0;
//    size_t	len;

	(void) data;

  //  len = strlen(file);
//    if (len < 5 || strcmp(file + len - 4, ".cub") != 0)
		ft_error("Error\nInvalid extension.", 0);
	fd = open(file, O_RDONLY);
//	if (fd == -1)
//		ft_error("Error\nCould not read the file\n", 0);
	//ft_readmap(fd, data);
	close(fd);
	//ft_map_parse(data);
}