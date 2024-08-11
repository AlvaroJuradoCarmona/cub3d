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
    int		fd;
	size_t	len;

	len = strlen(file);
	if (len < 5 || strcmp(file + len - 4, ".cub") != 0)
		ft_putendl_fd(EXTENSION_ERR, STDERR_FILENO);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_putendl_fd(FILE_ERR, STDERR_FILENO);
	//ft_readmap(fd, data);
	close(fd);
	//ft_map_parse(data);
}