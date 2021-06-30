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
}				t_points;
#endif
