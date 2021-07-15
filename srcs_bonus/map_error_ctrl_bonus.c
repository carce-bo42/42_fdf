#include "fdf_bonus.h"

void	init_map_data(t_data *data)
{
	data->col = 0;
	data->row = 0;
}

void	check_map(int fd, char **line, t_data *data)
{
	int	rows;
	int	gnl_ret;

	gnl_ret = 1;
	rows = 0;
	while (1)
	{
		gnl_ret = get_next_line(fd, line);
		if (gnl_ret == -1)
			break ;
		if (gnl_ret == 0 && **line == '\0' && rows != 0)
		{
			free(*line);
			break ;
		}
		line_error_control(line, data);
		rows++;
		if (gnl_ret == 0)
			break ;
	}
	if (gnl_ret == -1)
		file_error();
	data->row = rows;
}

void	error_ctrl(char *file, t_data *data)
{
	int		fd;
	char	*line;

	init_map_data(data);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		file_error();
	check_map(fd, &line, data);
	close (fd);
}
