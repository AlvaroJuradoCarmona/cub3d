#include "../../inc/cub3d.h"

static int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

int	ft_iswall(t_coords p, t_data *data)
{
	t_coords	pcasted;

	pcasted.x = p.x / BLOCKSIZE;
	pcasted.y = p.y / BLOCKSIZE;
	if (pcasted.x >= data->map_width || pcasted.y >= data->map_height || \
	pcasted.x < 0 || pcasted.y < 0)
		return (1);
	else if (data->map[pcasted.y][pcasted.x] == '1')
		return (1);
	else if (data->map[pcasted.y][pcasted.x] == '2')
		return (2);
	else if (data->map[pcasted.y][pcasted.x] == 'F')
		if (p.x % BLOCKSIZE >= ft_abs(data->chest_img->width - BLOCKSIZE) / 2 && \
		p.x % BLOCKSIZE <= (BLOCKSIZE - (int)data->chest_img->width))
			if (p.y % BLOCKSIZE >= ft_abs(data->chest_img->width - BLOCKSIZE) / \
		2 && p.y % BLOCKSIZE <= (BLOCKSIZE - (int)data->chest_img->width))
				return (3);
	return (0);
}