/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_identifiers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 12:38:25 by fsantama          #+#    #+#             */
/*   Updated: 2024/08/29 12:38:25 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int ft_find_identifier(char *line, t_data *data, int j)
{
    if (line[0] == '\n')
		return (-1);
	else if (ft_strncmp("NO ", &line[j], 3) == 0 && !data->iden[0])
		return (0);
	else if (ft_strncmp("SO ", &line[j], 3) == 0 && !data->iden[1])
		return (1);
	else if (ft_strncmp("WE ", &line[j], 3) == 0 && !data->iden[2])
		return (2);
	else if (ft_strncmp("EA ", &line[j], 3) == 0 && !data->iden[3])
		return (3);
	else if (ft_strncmp("F ", &line[j], 2) == 0 && !data->iden[4])
		return (4);
	else if (ft_strncmp("C ", &line[j], 2) == 0 && !data->iden[5])
        return (5);
    ft_error("Error: Duplicated identifier.", 0);
    return (-2);
}

/**
 * @brief 
 * 
 * @param fd 
 * @param data 
 * @param line 
 * @return char* 
 */
char *ft_parse_identifiers(int fd, t_data *data, char *line)
{
    int iden;
    int i;
    int j;

    i = 0;
    while (line && i <= 5)
    {   
        j = 0;
        while (line[j] == ' ')
            j++;
        iden = ft_find_identifier(line, data, j);
        if (iden >= 0 && iden <= 5)
		{
			j += 2;
			while (line[j] == ' ')
				j++;
			data->iden[iden] = ft_substr(line + j, 0, ft_strlen(line + j) - 1);
			i++;
		}
		ft_free_and_null((void **)&line);
		line = get_next_line(fd);
    }
    /*if (!line || !ft_extract_color(data->ids[4], &data->color.floor) || \
	!ft_extract_color(data->ids[5], &data->color.ceiling))
        ft_error("Error: File doesn't contain a valid map.", 0);*/
    return line;
}