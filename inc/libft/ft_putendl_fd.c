/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:21:40 by fsantama          #+#    #+#             */
/*   Updated: 2023/08/22 18:08:02 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Write a string followed by a newline to a file descriptor.
 *
 * This function writes the string 's' to the specified file descriptor 'fd',
 * followed by a newline character ('\n').
 *
 * @param s The string to be written.
 * @param fd The file descriptor to which the string is written.
 */
void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}
