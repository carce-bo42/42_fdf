#include "fdf.h"

void	arg_error(void)
{
	ft_putstr_fd(ANSI_COLOR_GREEN, 2);
	ft_putstr_fd("Usage: ./fdf <filename>.fdf\n", 2);
	ft_putstr_fd(ANSI_UNSET_GREEN, 2);
	exit(0);
}

void	file_error(void)
{
	ft_putstr_fd("./fdf : Error reading the map\n", 2);
	exit(0);
}

void	format_error(char *str)
{
	free(str);
	ft_putstr_fd("./fdf : Error in map format\n", 2);
	exit(0);
}

void	rgb_format_error(char *str)
{
	free(str);
	ft_putstr_fd("./fdf : colors (if specified) ", 2);
	ft_putstr_fd("have to be like: 0xFFFFFFi\n", 2);
	exit(0);
}

void	line_length_error(char *str)
{
	free(str);
	ft_putstr_fd("./fdf : error in line length. ", 2);
	ft_putstr_fd("Make sure the map is recangular\n", 2);
	exit(0);
}
