/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 08:45:25 by fsantama          #+#    #+#             */
/*   Updated: 2024/10/01 10:41:08 by fsantama         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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

# define WIDTH 1920
# define HEIGHT 1080

// Definiciones de teclas
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307

# define INVALID_ARGC "Error. Enter a single map as argument\n"

// Definir el tamaño del bloque y la conversión a radianes
# define BLOCKSIZE 64
# define TORADIANS (M_PI / 180.0)

typedef struct s_ray
{
	char	player_dir;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	int		side;
	int		draw_start;
	int		draw_end;
	double	perp_wall_dist;
	int		line_height;
	double	wall_x;
}	t_ray;

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

// Estructura para almacenar valores del jugador
typedef struct  s_player
{
    t_pos       pos;
    double      angle;
}               t_player;

// Estructura para almacenar los valores de color
typedef struct  s_pixels
{
    int         r;  // Componente rojo
    int         g;  // Componente verde
    int         b;  // Componente azul
    int         a;  // Componente alfa (transparencia)
}               t_pixels;

// Estructura para almacenar los datos del mapa
typedef struct  s_map
{
    int         *img;
    int         width;
    int         height;
    char        **map;
    t_pixels    floor_color;    // Color del suelo
    t_pixels    ceiling_color;  // Color del techo
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
    t_player    player;        // Información del jugador
    void *mlx; // puntero al entorno MLX
    void *win; // puntero a la ventana MLX
    void *full_img; // imagen completa
    void *background_img; // imagen de fondo
    void *victory_img; // imagen de victoria
    void *minimap; // minimapa
    void *player_img; // imagen del jugador
    void *chest_img; // imagen del cofre
    int time_counter; // contador de tiempo
    int open_coldown; // cooldown de apertura
    void *time; // para mostrar el tiempo
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
void	ft_split_free(char **str);
int     ft_split_size(char **split);
void    ft_parse_map(t_data *data);
void    ft_initial_cleaner(t_data *data);
void	ft_init_images(t_data *data);


#endif
