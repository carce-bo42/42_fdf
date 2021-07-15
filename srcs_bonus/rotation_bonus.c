#include "fdf_bonus.h"

void	adjust_rotation(t_mlx *mlx, int keycode)
{
	double	angle;
	double	increment;

	increment = 0.1;
	if (keycode == A)
		increment = -0.1;
	angle = mlx->data->rot_angle;
	if (angle <= 2.0 * M_PI && angle >= -2.0 * M_PI)
		mlx->data->rot_angle += increment;
	else
		mlx->data->rot_angle = increment;
}

void	rotation(double *x, double *y, double angle)
{
	double	aux_x;
	double	aux_y;

	aux_x = *x;
	aux_y = *y;
	*x = aux_x * cos(angle) + aux_y * sin(angle);
	*y = aux_x * sin(angle) - aux_y * cos(angle);
}
