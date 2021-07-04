#include "fdf.h"

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
	printf("rows = %i\n", rows);
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
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		arg_error();
	error_ctrl(argv[1], &data);
	//system("leaks fdf");
	return (0);
}

/*
int	main()
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_points	points;
	int	scale_factor;
	int	a;
	int	b;
	int	l;
	int	c;

	if (argc != 2)
		arg_error();




	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 2160, 1360, "Hello World!");

	img.img = mlx_new_image(mlx, 2160, 1360);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, 
			&img.line_length, &img.endian);
	points.color = 0xff;
	c = 100;
	l = 100;

	// Scale factor determination.
	if (c >= 45)
		scale_factor = ((800 - (800/c) - ((800 * 800)/(c * c)) + 2)/c);
	else if (c >= 20)
		scale_factor = (15 - (c*c)/500);
	else if (c >= 10)
		scale_factor = (25 - (c*c)/150);
	else if (c >= 7)
		scale_factor = (50 - (c*c)/100);
	else if (c >= 5)
		scale_factor = (60 - (c * c)/100);
	else
		scale_factor = (100 - (c * c) /10);
	c = scale_factor * c;
	l = scale_factor * l;

	// Drawing the edge of the plane.
	a = l/2;
	b = c/2;
	points.xi = (a + b) * cos (M_PI/6) + 1080;
	points.yi = (b - a) * sin(M_PI/6) + 680;
	a = -l/2;
	b = c/2;
	points.xf = (a + b) * cos (M_PI/6) + 1080;
	points.yf = (b - a) * sin(M_PI/6) + 680;
	draw_line(&points, &img);

	a = -l/2;
	b = -c/2;
	points.xi = (a + b) * cos (M_PI/6) + 1080;
	points.yi = (b - a) * sin(M_PI/6) + 680;
	a = -l/2;
	b = c/2;
	points.xf = (a + b) * cos (M_PI/6) + 1080;
	points.yf = (b - a) * sin(M_PI/6) + 680;
	draw_line(&points, &img);

	a = -l/2;
	b = -c/2;
	points.xi = (a + b) * cos (M_PI/6) + 1080;
	points.yi = (b - a) * sin(M_PI/6) + 680;
	a = l/2;
	b = -c/2;
	points.xf = (a + b) * cos (M_PI/6) + 1080;
	points.yf = (b - a) * sin(M_PI/6) + 680;
	draw_line(&points, &img);

	a = l/2;
	b = -c/2;
	points.xi = (a + b) * cos (M_PI/6) + 1080;
	points.yi = (b - a) * sin(M_PI/6) + 680;
	a = l/2;
	b = c/2;
	points.xf = (a + b) * cos (M_PI/6) + 1080;
	points.yf = (b - a) * sin(M_PI/6) + 680;
	draw_line(&points, &img);

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}*/
