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
# include <stdarg.h>
# include "MLX42/include/MLX42/MLX42.h"
# include "Libft/libft.h"
# include "ft_printf/ft_printf.h"

// Definiciones de teclas
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307

# define INVALID_ARGC "Error. Enter a single map as argument\n"
# define INVALID_EXT "Error. Invalid extension\n"
# define INVALID_FILE "Error. Invalid file\n"

/*---------------------------- HEADER ----------------------------*/

# define HEADER  "\033[36;1m                       ____      _    _____ ____  \n\
                      / ___|   _| |__|___ /|  _ | \n\
                     | |  | | | |  _ | |_ || | | |\n\
                     | |__| |_| | |_) |__) | |_| |\n\
                      |____|__ _|_ __/____/|____/ \n\
                                                   \n\
\033[37;1m                  A simple FPS project implemented in C \n\
		                 By \n\
		    --- ajurado- && fsantama --- \n\
\n\033[0m"

// Estructura para almacenar coordenadas simples (x, y)
typedef struct  s_coords
{
    int         x;
    int         y;
}               t_coords;

// Estructura para almacenar posiciones (doble precisión)
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
    char        *iden[6];
    int         screen_width;
    int         screen_height;
    t_img       img;
    t_map       map_close;
    t_map       map_open;
    bool        pause;
    bool        door_open;
    bool        pass_door;
    bool        cursor_hook;
    char        **map;         // Almacena el mapa
    int         map_height;    // Almacena la altura del mapa
    int         map_width;     // Almacena el ancho del mapa
}               t_data;


// Prototipos de funciones
char    *get_next_line(int fd);
int     main(int argc, char **argv);
void    ft_print_header(void);
void    ft_init_data(t_data *data);
void    ft_parse_data(char *file, t_data *data);
void    ft_error(const char *prompt, int num_args, ...);
void    ft_read_map(int fd, t_data *data);
void    ft_check_map(char *map, t_data *data);
void    ft_normalize_map(char *map, t_data *data);
char    *ft_parse_identifiers(int fd, t_data *data, char *line);
char    *ft_free_and_join(char *s1, char *s2);
void    ft_free_and_null(void **ptr);
void    ft_free(void *ptr);
int     ft_split_size(char **split);


// Agregar el prototipo de ft_is_invalid_value si es necesario
bool    ft_is_invalid_value(char c); 

#endif
