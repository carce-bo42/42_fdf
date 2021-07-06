#include "fdf.h"

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
