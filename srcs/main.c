#include "fdf.h"

void	give_scale_factor(t_data *data)
{
	double	c;

	c = fmax(data->col, data->row);
	if (c >= 300)
		data->s_fct = 0.333;
	if (c >= 100)
		data->s_fct = 8;
	if (c >= 45)
		data->s_fct = 2 * ((300 - (300 / c) - ((300 * 300) / (c * c)) + 2) / c);
	else if (c >= 20)
		data->s_fct = (15 - (c * c) / 500);
	else if (c >= 10)
		data->s_fct = (25 - (c * c) / 150);
	else if (c >= 7)
		data->s_fct = (50 - (c * c) / 100);
	else if (c >= 5)
		data->s_fct = (60 - (c * c) / 100);
	else
		data->s_fct = (100 - (c * c) / 10);
}

void	start_mlx(t_mlx *mlx, t_data *data)
{
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, 2160, 1360, "FdF carce-bo");
	data->img = mlx_new_image(mlx->mlx, 2160, 1360);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
}

int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
	{
		mlx_clear_window(mlx->mlx, mlx->mlx_win);
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
		exit(0);
	}
	return (0);
}

int	destructor(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit(0);
	return (0);
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
	close(fd);
	mlx_key_hook(mlx.mlx_win, key_hook, &mlx);
	mlx_hook(mlx.mlx_win, 17, 0, destructor, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
