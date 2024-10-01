/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:19:41 by fsantama          #+#    #+#             */
/*   Updated: 2023/08/22 18:11:42 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
* @brief Write a string to a file descriptor.
*
* This function writes the string 's' to the specified file descriptor 'fd'.
*
* @param s The string to be written.
* @param fd The file descriptor to which the string is written.
*/
void	ft_putstr_fd(char *s, int fd)
{
	write (fd, s, ft_strlen(s));
}
