#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

/* Function that draws a line between two points. How ? Still trying to
 * figure out :D */
void	draw_line(t_points *points, t_data *data);

int	main()
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		x = 100;
	int		y = 100;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello World!");

	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, 
			&img.line_length, &img.endian);
	while (x < 1000)
	{
		y = 100;
		while (y < 1000)
			my_mlx_pixel_put(&img, x, y++, 0x00FF0000);
		x++;
	}
	//printf("line_length: %i\nbits_per_pixel: %i\n", img.line_length, img.bits_per_pixel);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
