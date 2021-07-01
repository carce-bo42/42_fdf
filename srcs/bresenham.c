#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

/* Function that draws a line between two points. How ? Still trying to
 * figure out :D */
void	draw_line(t_points *points, t_data *data)
{
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
