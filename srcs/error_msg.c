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
	ft_putstr_fd("./fdf : Error reading the map ", 2);
	exit(0);
}

void	format_error(char *str)
{
	free(str);
	ft_putstr_fd("./fdf : Error in map format", 2);
	exit(0);
}

void	rgb_format_error(char *str)
{
	free(str);
	ft_putstr_fd("./fdf : colors (if specified) have to be like: 0xFFFFFF", 2);
	exit(0);
}

void	error_msg(void)
{
	char	*str;

	str = strerror(errno);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(0);
}
