#ifndef FDF_BONUS_H
# define FDF_BONUS_H
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
# define MAX_HEIGHT 600
# define MIN_HEIGHT -600
# define ATOL_ERROR 11111111111
# define ANSI_COLOR_GREEN "\033[0;32m"
# define ANSI_UNSET_GREEN "\033[0m"

typedef struct s_mlx
{
	void			*mlx;
	void			*mlx_win;
	char			*file;
	int				fd;
	struct s_data	*data;
}				t_mlx;

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			col;
	int			row;
	double		s_fct;
	double		zoom;
	double		trans_x;
	double		trans_y;
	double		rot_angle;
}				t_data;

typedef struct s_points
{
	int		xi;
	int		yi;
	int		zi;
	int		xf;
	int		yf;
	int		zf;
	int		clr_c;
	int		clr_f;
}				t_points;

typedef struct s_draw
{
	int		dx;
	int		dy;
	int		inc;
	int		diff;
	int		x_i;
	int		y_i;
	int		clr_i;
}				t_draw;

typedef struct s_matrix
{
	int	*mat_prv[2];
	int	*mat_now[2];
	int	size;
}				t_mat;

t_points	*reverse_points(t_points *points);
void		plot_line_high(t_points *points, t_data *data);
void		plot_line_low(t_points *points, t_data *data);
void		init_utils_low(t_draw *utils, t_points *points);
void		init_utils_high(t_draw *utils, t_points *points);
void		draw_line(t_points *points, t_data *data);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		error_ctrl(char *file, t_data *data);
void		line_error_control(char **line, t_data *data);
void		check_format(char *str, t_data *data);
void		check_arg(char *str);
void		arg_error(void);
void		file_error(void);
void		format_error(char *str);
void		rgb_format_error(char *str);
void		line_length_error(char *str);
void		init_map_data(t_data *data);
void		init_color_grad(t_draw *utils, t_points *pnt);
void		check_map(int fd, char **line, t_data *data);
void		start_mlx(t_mlx *mlx, t_data *data);
void		give_scale_factor(t_data *data);
void		draw_iso_right(t_points *pnt, t_data *data, int *r, int *c);
void		draw_iso_top(t_points *pnt, t_data *data, int *r, int *c);
void		draw_rightop_line(t_mat *mat, t_data *data, int *row);
void		draw_right_line(int *mat[2], t_data *data);
void		draw_image(int fd, t_data *data);
void		fill_row_matrix(t_mat *mat, char **line, int *row, int *true_row);
void		rewrite_previous_line(t_mat *mat);
void		line_to_matrix(int **mat, char **line);
void		init_row_matrix(int columns, t_mat *row_mats);
void		free_matrix(t_mat *mat, int row);

char		*ft_atolstr(char *str);
char		*ft_rgbstr(char *str);
long		ft_atol(char *str);
int			get_color(char *str);
int			get_pixel_color(t_draw *utils, t_points *pnt);
int			check_rgb(char *str);
/* BONUS RELLATED FUNCTIONS */

# define A 0
# define D 2
# define ESC 53

void		rotation(double *x, double *y, double angle);
int			key_hook(int keycode, t_mlx *mlx);
int			destroy_and_exit(t_mlx *mlx);
void		adjust_rotation(t_mlx *mlx, int keycode);
int			full_draw(t_mlx *mlx);
#endif
