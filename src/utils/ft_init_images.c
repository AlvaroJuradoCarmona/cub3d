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
/*
// Función auxiliar para cargar imágenes y texturas
static void init_images_aux(t_data *data)
{
    
    data->background_img = ft_img_by_text(data, "./src/imgs/galaxy.png", 0, 0);
    data->full_img = mlx_new_image(data->mlx, data->screen_width, data->screen_height);
    if (!data->full_img)
        ft_img_failure(data);
    if (mlx_image_to_window(data->mlx, data->full_img, 0, 0) == -1)
        ft_img_failure(data);

    data->victory_img = ft_img_by_text(data, "./src/imgs/victory.png", 0, 0);
    data->victory_img->enabled = 0; // La imagen de victoria está deshabilitada por defecto

    // Cargar y posicionar el minimapa
    data->minimap = mlx_new_image(data->mlx, MINIMAP_SIZE, MINIMAP_SIZE);
    if (!data->minimap)
        ft_img_failure(data);
    if (mlx_image_to_window(data->mlx, data->minimap, data->screen_width - MINIMAP_SIZE, 0) == -1)
        ft_img_failure(data);

    // Cargar y posicionar el rayo del jugador
    data->player.ray_img = mlx_new_image(data->mlx, MINIMAP_SIZE, MINIMAP_SIZE);
    if (!data->player.ray_img)
        ft_img_failure(data);
    if (mlx_image_to_window(data->mlx, data->player.ray_img, 
        data->screen_width - MINIMAP_SIZE / 2 - data->player.ray_img->width / 2, 
        MINIMAP_SIZE / 2 - data->player.ray_img->height / 2) == -1)
        ft_img_failure(data);

    // Cargar la imagen del jugador
    data->player.img = ft_img_by_text(data, "./src/imgs/ufo.png", 
        data->screen_width - MINIMAP_SIZE / 2 - 25, MINIMAP_SIZE / 2 - 25);

    // Cargar la imagen del cofre
    data->chest_img = ft_img_by_text(data, "./src/imgs/chest.png", 0, 0);
}
*/
// Función principal para inicializar las imágenes y texturas
void ft_init_images(t_data *data)
{
    printf("init_images\n");

   // data->background_img = NULL;

    data->mlx = mlx_init(WIDTH, HEIGHT, "Cub3D", false);
    if (!data->mlx)
    {
        ft_error("Error: MLX init failure", 0);
        ft_initial_cleaner(data);
        exit(EXIT_FAILURE);
    }

    // Inicializar mapas con las dimensiones correctas
    data->map_close.width = data->map_width * BLOCKSIZE;
    data->map_close.height = data->map_height * BLOCKSIZE;
    data->map_close.img = ft_calloc(data->map_close.width * data->map_close.height, sizeof(uint8_t));

    data->map_open.img = ft_calloc(data->map_close.width * data->map_close.height, sizeof(uint8_t));

    // Cargar texturas adicionales
//    init_images_aux(data);

    // Desactivar cofre al inicio
//    data->chest_img->enabled = 0;

    // Inicializar temporizadores
    data->time_counter = 0;
    data->open_coldown = -30000;

    // Mostrar el tiempo en pantalla
//    data->time = mlx_put_string(data->mlx, "TIME: 0", data->screen_width - MINIMAP_SIZE / 2 - 100, MINIMAP_SIZE + 10);
}
