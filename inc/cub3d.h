/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 08:45:25 by fsantama          #+#    #+#             */
/*   Updated: 2024/10/02 10:21:05 by fsantama         ###   ########.fr       */
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
# include "libft/libft.h"
# include <stdint.h>
# include <stdbool.h>

# define WIDTH 1920
# define HEIGHT 1024
# define MINIMAP_SIZE 400
# define PLAYER_SIZE 16
# define BLOCKSIZE 200
# define COLDOWN 3
# define ANGLE 60
# define PI 3.141592653589793
# define TORADIANS 0.017453292519943295
# define VELOCITY 16

// Definiciones de teclas
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307

# define INVALID_ARGC "Error. Enter a single map as argument\n"

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
typedef struct s_player
{
	t_coords			pos;
	double				angle;
	mlx_texture_t		*texture;
	mlx_image_t			*img;
	mlx_image_t			*ray_img;
}		t_player;

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
    uint8_t         *img;
    int         width;
    int         rwidth;
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

typedef struct s_wall_texture
{
	mlx_image_t			*n;
	mlx_image_t			*s;
	mlx_image_t			*w;
	mlx_image_t			*e;
	mlx_image_t			*door;
}		t_wall_texture;

typedef struct s_color
{
	t_pixels	white;
	t_pixels	gray;
	t_pixels	blue;
	t_pixels	green;
	t_pixels	golden;
	t_pixels	red;
	t_pixels	ceiling;
	t_pixels	floor;
}		t_color;

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
	mlx_t			*mlx;
    mlx_image_t *full_img; // imagen completa
    int open_coldown; // cooldown de apertura
    double			aux;
	mlx_image_t		*galaxy_i;
    t_wall_texture	wall;
    t_color color;
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
void	ft_map_construct(t_data *data);
void	ft_put_rgbcolor(uint8_t *pixels, t_pixels color, bool random);
void	ft_put_rgbimg(uint8_t *dest, uint8_t *or);
void	raycasting(t_data *data, t_coords pos);
int     ft_iswall(t_coords p, t_data *data);
void	ft_keyboard_hooks(void *param);
void	ft_cursor_hook(double x2, double y2, void *param);
void	ft_redraw(t_data *data, double angle);
void	ft_initial_cleaner(t_data *data);
void	ft_img_failure(t_data *data);
void	ft_move(t_data *data, t_coords pos, double x, double y);
int     ft_check_player_abroad(t_coords p, t_data *data, bool doors);
void	ft_swap(void *a, void *b, size_t size);

#endif
