#include "fdf_bonus.h"

void	change_view(t_mlx *mlx)
{
	if (mlx->data->view_angle == M_PI / 6)
		mlx->data->view_angle = M_PI / 4;
	else
		mlx->data->view_angle = M_PI / 6;
}

void	change_z_factor(t_mlx *mlx, int keycode)
{
	double	z_factor;
	int		more;
	int		less;

	less = 1;
	more = 1;
	z_factor = 0.05;
	if (mlx->data->z_scale_factor > 10.0)
		more = 0;
	if (mlx->data->z_scale_factor < -10.0)
		less = 0;
	if (keycode == KEY_Z && more == 1)
		mlx->data->z_scale_factor += z_factor;
	if (keycode == KEY_X && less == 1)
		mlx->data->z_scale_factor -= z_factor;
}

int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESC)
		destroy_and_exit(mlx);
	else if (keycode == KEY_A || keycode == KEY_D)
		adjust_rotation(mlx, keycode);
	else if (keycode == RIGHT_ARROW || keycode == LEFT_ARROW)
		translate_x(mlx, keycode);
	else if (keycode == UP_ARROW || keycode == DOWN_ARROW)
		translate_y(mlx, keycode);
	else if (keycode == KEY_PLUS || keycode == KEY_MINUS)
		zoom_camera(mlx, keycode);
	else if (keycode == KEY_V)
		change_view(mlx);
	else if (keycode == KEY_Z || keycode == KEY_X)
		change_z_factor(mlx, keycode);
	else
		return (0);
	full_draw(mlx);
	return (0);
}

int	destroy_and_exit(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit(0);
	return (0);
}
