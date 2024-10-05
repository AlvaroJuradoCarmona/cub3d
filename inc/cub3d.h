/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajurado- <ajurado-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 11:31:18 by ajurado-          #+#    #+#             */
/*   Updated: 2024/10/05 11:31:18 by ajurado-         ###   ########.fr       */
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
# include "libft/libft.h"
# include <stdint.h>
# include <stdbool.h>

# define WIDTH 1920
# define HEIGHT 1024
# define PLAYER_SIZE 16
# define BLOCKSIZE 200
# define COLDOWN 3
# define ANGLE 60
# define PI 3.141592653589793
# define TORADIANS 0.017453292519943295
# define VELOCITY 16

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307

# define INVALID_ARGC "Error. Enter a single map as argument\n"

typedef struct s_coords
{
	int	x;
	int	y;
}	t_coords;

typedef struct s_player
{
	t_coords	pos;
	double		angle;
}		t_player;

typedef struct s_pixels
{
	int	r;
	int	g;
	int	b;
	int	a;
}	t_pixels;

typedef struct s_map
{
	uint8_t		*img;
	int			width;
	int			rwidth;
	int			height;
	char		**map;
	t_pixels	floor_color;
	t_pixels	ceiling_color;
}	t_map;

typedef struct s_wall_texture
{
	mlx_image_t			*n;
	mlx_image_t			*s;
	mlx_image_t			*w;
	mlx_image_t			*e;
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

typedef struct s_data
{
	char			*iden[6];
	int				screen_width;
	int				screen_height;
	t_map			map_close;
	t_map			map_open;
	bool			pause;
	bool			door_open;
	char			**map;
	int				map_height;
	int				map_width;
	t_player		player;
	mlx_t			*mlx;
	mlx_image_t		*full_img;
	int				open_coldown;
	double			aux;
	t_wall_texture	wall;
	t_color			color;
}	t_data;

char	*get_next_line(int fd);
int		main(int argc, char **argv);
void	ft_print_header(void);
void	ft_init_data(t_data *data);
void	ft_parse_data(char *file, t_data *data);
void	ft_error(const char *prompt, int num_args, ...);
void	ft_read_map(int fd, t_data *data);
void	ft_check_map(char *map, t_data *data);
void	ft_normalize_map(char *map, t_data *data);
char	*ft_parse_identifiers(int fd, t_data *data, char *line);
char	*ft_free_and_join(char *s1, char *s2);
void	ft_free_and_null(void **ptr);
void	ft_free(void *ptr);
void	ft_split_free(char **str);
int		ft_split_size(char **split);
void	ft_parse_map(t_data *data);
void	ft_initial_cleaner(t_data *data);
void	ft_init_images(t_data *data);
void	ft_map_construct(t_data *data);
void	ft_put_rgbcolor(uint8_t *pixels, t_pixels color, bool random);
void	ft_put_rgbimg(uint8_t *dest, uint8_t *or);
void	raycasting(t_data *data, t_coords pos);
int		ft_iswall(t_coords p, t_data *data);
void	ft_keyboard_hooks(void *param);
void	ft_redraw(t_data *data, double angle);
void	ft_initial_cleaner(t_data *data);
void	ft_img_failure(t_data *data);
void	ft_move(t_data *data, t_coords pos, double x, double y);
int		ft_check_player_abroad(t_coords p, t_data *data, bool doors);
void	ft_swap(void *a, void *b, size_t size);

#endif
