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

void free_and_null(void **ptr)
{
    if (ptr && *ptr)
    {
        free(*ptr);
        *ptr = NULL;
    }
}

// Esta función maneja errores, libera memoria, muestra un mensaje de error y termina el programa.
void ft_error(char *prompt, int num_args, ...)
{
    va_list args;
    void *ptr;
    int i;

    if (num_args > 0) // Si hay argumentos para liberar.
    {
        va_start(args, num_args);
        for (i = 0; i < num_args; ++i)
        {
            ptr = va_arg(args, void *);
            if (ptr)
                free_and_null((void **)&ptr);
        }
        va_end(args);
    }

    fprintf(stderr, "\033[31;1m%s\n\033[0m", prompt); // Imprimir mensaje de error en rojo y negrita.
    exit(EXIT_FAILURE); // Terminar el programa con estado de fallo.
}