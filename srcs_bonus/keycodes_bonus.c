#include "fdf_bonus.h"

int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESC)
		destroy_and_exit(mlx);
	if (keycode == KEY_A || keycode == KEY_D)
		adjust_rotation(mlx, keycode);
	if (keycode == RIGHT_ARROW || keycode == LEFT_ARROW)
		translate_x(mlx, keycode);
	if (keycode == UP_ARROW || keycode == DOWN_ARROW)
		translate_y(mlx, keycode);
	if (keycode == KEY_PLUS || keycode == KEY_MINUS)
		zoom_camera(mlx, keycode);
	return (0);
}

int	destroy_and_exit(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit(0);
	return (0);
}
