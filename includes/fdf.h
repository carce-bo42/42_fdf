#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_points
{
	int		xi;
	int		yi;
	int		xf;
	int		yf;
	int		color;
}				t_points;

typedef struct	s_draw
{
	int		dx;
	int		dy;
	int		inc;
	int		diff;
}				t_draw;

t_points	*reverse_points(t_points *points);
void	plot_line_high(t_points *points, t_data *data);
void	plot_line_low(t_points *points, t_data *data);
void	init_utils_low(t_draw *utils, t_points *points);
void	init_utils_high(t_draw *utils, t_points *points);
void	draw_line(t_points *points, t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
#endif
