#include "fdf_bonus.h"

void	adjust_rotation(t_mlx *mlx, int keycode)
{
	double	angle;
	double	increment;

	increment = 0.1;
	if (keycode == A)
		increment = -0.1;
	angle = mlx->data->rot_angle;
	if (angle <= 2 * M_PI && angle >= -(2 * M_PI))
		mlx->data->rot_angle += increment;
	else
		mlx->data->rot_angle = increment;
}

void	rotation(t_points *pnt, t_data *data)
{
	int	aux_x;
	int	aux_y;

	aux_x = pnt->xi;
	aux_y = pnt->yi;
	pnt->xi = aux_x * cos(data->rot_angle)
		- aux_y * sin(data->rot_angle);
	pnt->yi = aux_x * sin(data->rot_angle)
		+ aux_y * cos(data->rot_angle);
	aux_x = pnt->xf;
	aux_y = pnt->yf;
	pnt->xf = aux_x * cos(data->rot_angle)
		- aux_y * sin(data->rot_angle);
	pnt->yf = aux_x * sin(data->rot_angle)
		+ aux_y * cos(data->rot_angle);
}
