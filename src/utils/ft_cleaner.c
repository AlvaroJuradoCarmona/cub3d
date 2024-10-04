#include "../../inc/cub3d.h"

void	ft_img_failure(t_data *data)
{
	mlx_close_window(data->mlx);
	ft_error("Error\nImage/Texture failure", 0);
	ft_initial_cleaner(data);
	exit(EXIT_FAILURE);
}