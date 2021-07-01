#include "fdf.h"

int	main()
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_points	points;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello World!");

	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, 
			&img.line_length, &img.endian);
	points.xi = 200000;
	points.yi = 20000;
	points.xf = 1500;
	points.yf = 700;
	points.color = 0xff;
	draw_line(&points, &img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
