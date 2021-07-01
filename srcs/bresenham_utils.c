#include "fdf.h"

void	init_utils_high(t_draw *utils, t_points *points)
{
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
	while (points->yi < points->yf)
	{
		if (points->xi >= 1920 || points->yi >= 1080)
			break ;
		my_mlx_pixel_put(data, points->xi, points->yi, points->color);
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
		if (points->xi >= 1920 || points->yi >= 1080)
			break ;
		my_mlx_pixel_put(data, points->xi, points->yi, points->color);
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
