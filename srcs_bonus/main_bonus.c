#include "fdf_bonus.h"

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
	data->trans_x = 0.0;
	data->trans_y = 0.0;
	data->zoom = 0.0;
	data->rot_angle = 0.0;
}

int	full_draw(t_mlx *mlx)
{
	mlx->fd = open(mlx->file, O_RDONLY);
	mlx->data->img = mlx_new_image(mlx->mlx, 2160, 1360);
	mlx->data->addr = mlx_get_data_addr(mlx->data->img,
			&mlx->data->bits_per_pixel,
			&mlx->data->line_length, &mlx->data->endian);
	draw_image(mlx->fd, mlx->data);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->data->img, 0, 0);
	mlx_destroy_image(mlx->mlx, mlx->data->img);
	close(mlx->fd);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_mlx	mlx;

	if (argc != 2)
		arg_error();
	mlx.file = argv[1];
	mlx.data = &data;
	error_ctrl(mlx.file, &data);
	start_mlx(&mlx, &data);
	full_draw(&mlx);
	mlx_hook(mlx.mlx_win, 2, 3, key_hook, &mlx);
	mlx_hook(mlx.mlx_win, 17, (17L << 0), destroy_and_exit, &mlx);
	mlx_loop_hook(mlx.mlx, full_draw, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
