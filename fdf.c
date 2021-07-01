#include "fdf.h"

int	main()
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_points	points;
	int	a;
	int	b;
	int	l;
	int	c;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 2160, 1360, "Hello World!");

	img.img = mlx_new_image(mlx, 2160, 1360);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, 
			&img.line_length, &img.endian);
	points.color = 0xff;
	c = 3000;
	l = 800;

	a = l/2;
	b = c/2;
	points.xi = (a + b) * cos (M_PI/6) + 1080;
	points.yi = (b - a) * sin(M_PI/6) + 680;
	a = -l/2;
	b = c/2;
	points.xf = (a + b) * cos (M_PI/6) + 1080;
	points.yf = (b - a) * sin(M_PI/6) + 680;
	draw_line(&points, &img);

	a = -l/2;
	b = -c/2;
	points.xi = (a + b) * cos (M_PI/6) + 1080;
	points.yi = (b - a) * sin(M_PI/6) + 680;
	a = -l/2;
	b = c/2;
	points.xf = (a + b) * cos (M_PI/6) + 1080;
	points.yf = (b - a) * sin(M_PI/6) + 680;
	draw_line(&points, &img);

	a = -l/2;
	b = -c/2;
	points.xi = (a + b) * cos (M_PI/6) + 1080;
	points.yi = (b - a) * sin(M_PI/6) + 680;
	a = l/2;
	b = -c/2;
	points.xf = (a + b) * cos (M_PI/6) + 1080;
	points.yf = (b - a) * sin(M_PI/6) + 680;
	draw_line(&points, &img);

	a = l/2;
	b = -c/2;
	points.xi = (a + b) * cos (M_PI/6) + 1080;
	points.yi = (b - a) * sin(M_PI/6) + 680;
	a = l/2;
	b = c/2;
	points.xf = (a + b) * cos (M_PI/6) + 1080;
	points.yf = (b - a) * sin(M_PI/6) + 680;
	draw_line(&points, &img);

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
