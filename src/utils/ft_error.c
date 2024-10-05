/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 09:20:44 by fsantama          #+#    #+#             */
/*   Updated: 2024/08/07 09:20:44 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/**
 * @brief Libera la memoria apuntada por el puntero dado y lo establece en NULL.
 *
 * Esta función verifica si el puntero es válido y si la memoria ya ha sido
 * asignada. Si lo es, la memoria es liberada y el puntero se establece en NULL
 * para evitar errores de doble liberación o acceso a memoria no válida.
 *
 * @param ptr Doble puntero a la memoria que se quiere liberar.
 */
void	free_and_null(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

/**
 * @brief Muestra un mensaje de error, libera memoria si es necesario y 
 * termina el programa.
 *
 * Esta función se usa para manejar errores críticos. Muestra un mensaje 
 * en la salida estándar de errores (stderr),
 * libera cualquier memoria pasada como argumento (si la hay), y termina 
 * el programa con un código de error.
 *
 * @param prompt Mensaje de error que se mostrará.
 * @param num_args Número de punteros que se deben liberar.
 * @param ... Lista de argumentos de punteros que se quieren liberar 
 * antes de salir.
 *
 * @details Esta función utiliza argumentos variables para aceptar un 
 * número indefinido de punteros
 * que serán liberados mediante `free_and_null`. Después de liberar los 
 * punteros, el programa se termina.
 * Los punteros se pasan como `void**` para permitir su modificación 
 * (establecerlos a NULL después de la liberación).
 *
 * @return No retorna, ya que la función llama a `exit(EXIT_FAILURE)` para 
 * terminar el programa.
 */
void	ft_error(const char *prompt, int num_args, ...)
{
	va_list	args;
	void	**ptr;

	(void)prompt;
	(void)num_args;
	va_start(args, num_args);
	for (int i = 0; i < num_args; ++i)
	{
		ptr = va_arg(args, void **);
		free_and_null(ptr);
	}
	va_end(args);
	fprintf(stderr, "\033[31;1m%s\n\033[0m", prompt);
	exit(EXIT_FAILURE);
}
