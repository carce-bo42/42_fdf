#include "fdf_bonus.h"

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
