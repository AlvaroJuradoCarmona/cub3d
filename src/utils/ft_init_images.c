/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:12:17 by fsantama          #+#    #+#             */
/*   Updated: 2024/10/01 10:41:48 by fsantama         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../../inc/cub3d.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || ((unsigned char)c >= 9 && (unsigned char)c <= 13));
}

mlx_image_t	*ft_img_by_text(t_data *data, char *file, int x, int y)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;
	t_coords		pos;
	char			*aux;

	pos.x = 0;
	while (ft_isspace(file[pos.x]))
		pos.x++;
	pos.y = ft_strlen(file) - 1;
	while (ft_isspace(file[pos.y]) && pos.y > 0)
		pos.y--;
	aux = ft_substr(file, pos.x, pos.y - pos.x + 1);
	texture = mlx_load_png(aux);
	ft_free_and_null((void **)&aux);
	if (!texture)
		ft_img_failure(data);
	img = mlx_texture_to_image(data->mlx, texture);
	if (mlx_image_to_window(data->mlx, img, x, y) == -1)
		ft_img_failure(data);
	mlx_delete_texture(texture);
	return (img);
}

void	init_ids_imgs(t_data *data)
{
	data->wall.n = ft_img_by_text(data, data->iden[0], 0, 0);
	data->wall.s = ft_img_by_text(data, data->iden[1], 0, 0);
	data->wall.w = ft_img_by_text(data, data->iden[2], 0, 0);
	data->wall.e = ft_img_by_text(data, data->iden[3], 0, 0);
	data->wall.n->enabled = 0;
	data->wall.s->enabled = 0;
	data->wall.w->enabled = 0;
	data->wall.e->enabled = 0;
	data->wall.door = ft_img_by_text(data, "./src/imgs/door_ciel.png", 0, 0);
	data->wall.door->enabled = 0;
}

static void init_images_aux(t_data *data)
{
	data->full_img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->full_img)
		ft_img_failure(data);
	if (mlx_image_to_window(data->mlx, data->full_img, 0, 0) == -1)
		ft_img_failure(data);
	init_ids_imgs(data);
}

void ft_init_images(t_data *data)
{
    data->mlx = mlx_init(WIDTH, HEIGHT, "Cub3D", false);
    if (!data->mlx)
    {
        ft_error("Error: MLX init failure", 0);
        ft_initial_cleaner(data);
        exit(EXIT_FAILURE);
    }
    data->map_close.width = data->map_width * BLOCKSIZE;
	data->map_close.rwidth = data->map_width * BLOCKSIZE * 4;
	data->map_close.height = data->map_height * BLOCKSIZE;
	data->map_close.img = ft_calloc(data->map_close.rwidth * \
	data->map_close.height, sizeof(uint8_t));
	data->map_open.img = ft_calloc(data->map_close.rwidth * \
	data->map_close.height, sizeof(uint8_t));
	init_images_aux(data);
	data->open_coldown = -30000;
}
