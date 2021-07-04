#include "fdf.h"

/*Function that extracts an int from a string composed of isspace(3),
 * -/+ and digit chars,if written in the order:
 *   |isspace(3) * k | sign * 1 | '0' * k | digits * l | 
 *   where k is any positive whole number, and l is between 0 and 10.
 *   If it doesnt respect this format, or if the number is higher tha
 *   1000 or lower than -1000, the program raises an error
 *   outputting ATOL_ERROR=111111111111 (eleven 1's).*/
long	ft_atol(char *str)
{
	int		sign;
	long	out;

	sign = 1;
	out = 0;
	while (ft_isspace3(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (ft_isign(*str))
		str++;
	if (!ft_isdigit(*str))
		return (ATOL_ERROR);
	if (ft_numberlen(str) > 10)
		return (ATOL_ERROR);
	while (ft_isdigit(*str))
		out = out * 10 + *str++ - '0';
	if (!ft_isspace3(*str) && *str && !ft_iscoma(*str))
		return (ATOL_ERROR);
	out *= sign;
	if (out > MAX_HEIGHT || out < MIN_HEIGHT)
		return (ATOL_ERROR);
	return (out);
}

/*This function is supposed to be called whenever the parser finds
 * a comma after the number with the altitude. */
int	check_rgb(char *str)
{
	int	digits;

	if (ft_isspace3(*str) || !*str)
		return (1);
	str++;
	if (*str != '0')
		return (-1);
	str++;
	if (*str != 'x')
		return (-1);
	str++;
	digits = 0;
	if (!ft_ishexa(*str))
		return (-1);
	while (ft_ishexa(*str))
	{
		str++;
		digits++;
		if (digits == 6)
			break ;
	}
	if (!ft_isspace3(*str) && *str)
		return (-1);
	return (1);
}

/*Function that, after checking that a number is correctly formatted,
 * moves through the atol process and returns the position at which the
 * total string is left, to proceed with the next atol check. It has
 * an adjustment that takes care of it if the left of the string has
 * only isspaces or signs*/
char	*ft_atolstr(char *str)
{
	char	*aux;

	while (ft_isspace3(*str))
		str++;
	if (ft_isign(*str))
		str++;
	while (ft_isdigit(*str))
		str++;
	aux = str;
	while (*aux)
	{
		if (ft_isdigit(*aux) || ft_isign(*aux))
			return (str);
		aux++;
	}
	return (aux);
}

/*This one is easy. The format of hexas is very strict,
 * and so it will ONLY consist of 8 chars. which have to
 * be skipped to proceed with the parsing.*/
char	*ft_rgbstr(char *str)
{
	if (*str == ',')
		return (str + 9);
	return (str);
}

void	check_arg(char *str)
{
	char	*aux;

	aux = str;
	while (*aux)
	{
		if (!ft_ishexa(*aux) && !ft_isspace3(*aux)
			&& !ft_isign(*aux) && !ft_iscoma(*aux) && *aux != 'x')
			format_error(str);
		aux++;
	}
}

/*This function makes sure the map is in the correct format. This is,
 * same "number of numbers" on each line, non emptyness on an
 * in-between-of-file line, possibility of color specification in 
 * rgb on the format 0xFFFFFF, numbers are ints between -1000 and 1000.*/
void	check_format(char *str, t_data *data)
{
	char	*aux;
	int		nbrs;
	
	nbrs = 0;
	aux = str;
	while (*aux)
	{
		if (ft_atol(aux) == ATOL_ERROR)
			format_error(str);
		aux = ft_atolstr(aux);
		if (check_rgb(aux) == -1)
			rgb_format_error(str);
		aux = ft_rgbstr(aux);
		nbrs++;
	}
	if (nbrs == 0)
		line_length_error(str);
	if (data->col == 0)
		data->col = nbrs;
	if (nbrs != data->col)
		line_length_error(str);
}

void	line_error_control(char **line, t_data *data)
{
	char	*aux;

	aux = ft_strdup(*line);
	free(*line);
	check_arg(aux);
	check_format(aux, data);
	free(aux);
}
