#include "../cub3d.h"

void	ft_parse_file(t_data *data, char *f)
{
	int		fd;
	int		len;

	len = ft_strlen(f);
	if (len < 5 || ft_strncmp(".cub", &f[len - 4], 4) != 0)
		ft_putendl_fd(EXTENSION_ERR, STDERR_FILENO);
	fd = open(f, O_RDONLY);
	if (fd == -1)
		ft_putendl_fd(FILE_ERR, STDERR_FILENO);
	close(fd);
}