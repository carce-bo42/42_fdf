#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <sys/errno.h>
# include <string.h>
# define MAX_HEIGHT 1000
# define MIN_HEIGHT -1000
# define ATOL_ERROR 11111111111
# define ANSI_COLOR_GREEN "\033[0;32m"
# define ANSI_UNSET_GREEN "\033[0m"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		col;
	int		row;
}				t_data;

typedef struct s_points
{
	int		xi;
	int		yi;
	int		xf;
	int		yf;
	int		color;
}				t_points;

typedef struct s_draw
{
	int		dx;
	int		dy;
	int		inc;
	int		diff;
}				t_draw;

t_points	*reverse_points(t_points *points);
void		plot_line_high(t_points *points, t_data *data);
void		plot_line_low(t_points *points, t_data *data);
void		init_utils_low(t_draw *utils, t_points *points);
void		init_utils_high(t_draw *utils, t_points *points);
void		draw_line(t_points *points, t_data *data);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		line_error_control(char **line, t_data *data);
void		check_format(char *str, t_data *data);
void		check_arg(char *str);
void		arg_error(void);
void		file_error(void);
void		format_error(char *str);
void		rgb_format_error(char *str);
void		line_length_error(char *str);
void		init_map_data(t_data *data);
void		check_map(int fd, char **line, t_data *data);

char		*ft_atolstr(char *str);
long		ft_atol(char *str);
int			get_color(char *str);
#endif
