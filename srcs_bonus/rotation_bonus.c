#include "fdf_bonus.h"

void	zoom_camera(t_mlx *mlx, int keycode)
{
	double	added_zoom;
	int		more;
	int		less;

	more = 1;
	less = 1;
	added_zoom = 0.05;
	if (mlx->data->zoom > 3.0)
		more = 0;
	if (mlx->data->zoom < -0.9)
		less = 0;
	if (keycode == KEY_PLUS && more == 1)
		mlx->data->zoom += added_zoom;
	if (keycode == KEY_MINUS && less == 1)
		mlx->data->zoom -= added_zoom;
}

void	translate_x(t_mlx *mlx, int keycode)
{
	double	displacement;
	int		more;
	int		less;

	more = 1;
	less = 1;
	displacement = 10.0;
	if (mlx->data->trans_x > 2 * 1080)
		more = 0;
	if (mlx->data->trans_x < -2 * 1080)
		less = 0;
	if (keycode == RIGHT_ARROW && more == 1)
		mlx->data->trans_x += displacement;
	if (keycode == LEFT_ARROW && less == 1)
		mlx->data->trans_x -= displacement;
}

void	translate_y(t_mlx *mlx, int keycode)
{
	double	displacement;
	int		more;
	int		less;

	more = 1;
	less = 1;
	displacement = 10.0;
	if (mlx->data->trans_y > 2 * 680)
		more = 0;
	if (mlx->data->trans_y < -2 * 680)
		less = 0;
	if (keycode == DOWN_ARROW && more == 1)
		mlx->data->trans_y += displacement;
	if (keycode == UP_ARROW && less == 1)
		mlx->data->trans_y -= displacement;
}

void	adjust_rotation(t_mlx *mlx, int keycode)
{
	double	angle;
	double	increment;

	increment = 0.1;
	if (keycode == KEY_A)
		increment = -0.1;
	angle = mlx->data->rot_angle;
	if (angle <= 2.0 * M_PI && angle >= -2.0 * M_PI)
		mlx->data->rot_angle += increment;
	else
		mlx->data->rot_angle = increment;
}

void	rotation(double *x, double *y, double *z, t_data *data)
{
	double	aux_x;
	double	aux_y;

	aux_x = *x;
	aux_y = *y;
	*x = aux_x * cos(data->rot_angle) - aux_y * sin(data->rot_angle);
	*y = aux_x * sin(data->rot_angle) + aux_y * cos(data->rot_angle);
	*z = (1 + data->zoom) * (pow(cos(data->view_angle - M_PI / 6), 10)
			* (*z) * (1 + data->z_scale_factor));
}
