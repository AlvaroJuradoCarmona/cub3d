/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_header.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:22:01 by fsantama          #+#    #+#             */
/*   Updated: 2024/08/28 10:22:01 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * @brief Imprime el encabezado de bienvenida del juego.
 *
 * Esta función imprime en la salida estándar el encabezado (header) del juego, 
 * que incluye el título "CUB3D" y la información del proyecto en formato ASCII 
 * y con colores.
 * 
 * @note Utiliza `ft_printf` para realizar la impresión con formato.
 */
void ft_print_header(void)
{
    ft_printf("%s", HEADER);
}
