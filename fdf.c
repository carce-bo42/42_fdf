#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	init_utils_high(t_draw *utils, t_points *points)
{
	//printf("xi:%i, yi:%i, xf:%i, yf:%i\n", points->xi, points->yi, points->xf, points->yf);
	utils->dx = points->xf - points->xi;
	utils->dy = points->yf - points->yi;
	utils->inc = 1;
	if (utils->dx < 0)
	{
		utils->inc = -1;
		utils->dx = -1 * utils->dx;
	}
	utils->diff = (2 * utils->dx) - utils->dy;
}

void	plot_line_high(t_points *points, t_data *data)
{
	t_draw	utils;

	init_utils_high(&utils, points);
	//printf("dx:%i, dy:%i, diff:%i, inc:%i\n", utils.dx, utils.dy, utils.diff, utils.inc);
	//printf("xi:%i, yi:%i, xf:%i, yf:%i\n", points->xi, points->yi, points->xf, points->yf);
	while (points->yi < points->yf)
	{
		my_mlx_pixel_put(data, points->xi, points->yi, 0x00FF0000);
		if (utils.diff > 0)
		{
			points->xi += utils.inc;
			utils.diff += 2 * (utils.dx - utils.dy);
		}
		else
			utils.diff += 2 * utils.dx;
		points->yi += 1;
	}
}

void	init_utils_low(t_draw *utils, t_points *points)
{
	utils->dx = points->xf - points->xi;
	utils->dy = points->yf - points->yi;
	utils->inc = 1;
	if (utils->dy < 0)
	{
		utils->inc = -1;
		utils->dy = -1 * utils->dy;
	}
	utils->diff = (2 * utils->dy) - utils->dx;
}

void	plot_line_low(t_points *points, t_data *data)
{
	t_draw	utils;

	init_utils_low(&utils, points);
	while (points->xi < points->xf)
	{
		my_mlx_pixel_put(data, points->xi, points->yi, 0x00FF0000);
		if (utils.diff > 0)
		{
			points->yi += utils.inc;
			utils.diff += 2 * (utils.dy - utils.dx);
		}
		else
			utils.diff += 2 * utils.dy;
		points->xi += 1;
	}
}

t_points	*reverse_points(t_points *points)
{
	int	aux;

	aux = points->xf;
	points->xf = points->xi;
	points->xi = aux;
	aux = points->yf;
	points->yf = points->yi;
	points->yi = aux;
	return (points);
}


/* Function that draws a line between two points. How ? Still trying to
 * figure out :D */
void	draw_line(t_points *points, t_data *data)
{
	//printf("abs(yf - yi) = %i, abs(xf - xi) = %i\n", abs(points->yf - points->yi), abs(points->xf - points->xi));
	if (abs(points->yf - points->yi) < abs(points->xf - points->xi))
	{
		if (points->xi > points->xf)
			plot_line_low(reverse_points(points), data);
		else
			plot_line_low(points, data);
	}
	else
	{
		if (points->yi > points->yf)
			plot_line_high(reverse_points(points), data);
		else
			plot_line_high(points, data);
	}
}

int	main()
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	//int		x = 100;
	//int		y = 100;
	t_points	points;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello World!");

	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, 
			&img.line_length, &img.endian);
	points.xi = 100;
	points.yi = 100;
	points.xf = 180;
	points.yf = 78;
	draw_line(&points, &img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
