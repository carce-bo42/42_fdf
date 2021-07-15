#include "fdf_bonus.h"

int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == ESC)
		destroy_and_exit(mlx);
	if (keycode == A || keycode == D)
		rotate_and_draw(mlx, keycode);
	return (0);
}

int	destroy_and_exit(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit(0);
	return (0);
}
