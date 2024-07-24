#ifndef CUB3D_H
#define CUB3D_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <math.h>
#include "../MLX42/include/MLX42/MLX42.h"

// Definiciones de teclas (pueden variar dependiendo de la distribución de MinilibX)
#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_ESC 65307

// Estructura para almacenar las coordenadas
typedef struct  s_pos
{
    double      x;
    double      y;
}               t_pos;

// Estructura para almacenar los datos del mapa
typedef struct  s_map
{
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
    void        *mlx_ptr;
    void        *win_ptr;
    int         screen_width;
    int         screen_height;
    t_img       img;
    t_pos       pos;
    t_pos       dir;
    t_pos       plane;
    t_map       map;
}               t_data;

// Prototipos de funciones

int     main(int argc, char **argv);

#endif
