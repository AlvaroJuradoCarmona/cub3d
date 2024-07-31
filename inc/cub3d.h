/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 08:45:25 by fsantama          #+#    #+#             */
/*   Updated: 2024/07/25 08:45:25 by fsantama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "MLX42/include/MLX42/MLX42.h"

// Definiciones de teclas (pueden variar dependiendo de la distribución de MinilibX)
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307

# define INVALID_ARGC "Enter a single map as argument\n"

// Estructura para almacenar las coordenadas
typedef struct  s_pos
{
    double      x;
    double      y;
}               t_pos;

// Estructura para almacenar los datos del mapa
typedef struct  s_map
{
    int         *img;
    int         width;
    int         height;
    char        **map;
}               t_map;

// Estructura para almacenar datos de la imagen
typedef struct  s_img
{
    void        *img_ptr;
    int         *data;
    int         bpp;
    int         size_l;
    int         endian;
}               t_img;

// Estructura principal para almacenar todos los datos del juego
typedef struct  s_data
{
    int         screen_width;
    int         screen_height;
    t_img       img;
    t_map       map_close;
    t_map       map_open;
    bool        pause;
    bool        door_open;
    bool        pass_door;
    bool        cursor_hook;
}               t_data;

// Prototipos de funciones

int     main(int argc, char **argv);

void    ft_init_data(t_data *data);

#endif
