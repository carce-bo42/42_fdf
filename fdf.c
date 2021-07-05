#include "fdf.h"

void	start_mlx(t_mlx *mlx, t_data *data)
{
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, 2160, 1360, "FdF carce-bo");
	data->img = mlx_new_image(mlx->mlx, 2160, 1360);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, 
			&data->line_length, &data->endian);
}

void	give_scale_factor(t_data *data)
{
	double	c;

	c = fmax(data->col, data->row);
	if (c >= 300)
		data->s_fct = 0.333;
	if (c >= 45)
		data->s_fct = ((300 - (300/c) - ((300 * 300)/(c * c)) + 2)/c);
	else if (c >= 20)
		data->s_fct = (15 - (c*c)/500);
	else if (c >= 10)
		data->s_fct = (25 - (c*c)/150);
	else if (c >= 7)
		data->s_fct = (50 - (c*c)/100);
	else if (c >= 5)
		data->s_fct = (60 - (c * c)/100);
	else
		data->s_fct = (100 - (c * c) /10);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_mlx	mlx;
	int		fd;

	if (argc != 2)
		arg_error();
	error_ctrl(argv[1], &data);
	start_mlx(&mlx, &data);
	fd = open(argv[1], O_RDONLY);
	draw_image(fd, &data);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, data.img, 0, 0);
	//system("leaks fdf");
	mlx_loop(mlx.mlx);
	//printf("data->col = %i, data->row = %i\n", data.col, data.row);
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
