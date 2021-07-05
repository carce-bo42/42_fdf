#include "fdf.h"

/*This function will be used and should always be used when
 * there is cretainty regarding the existence of the char 
 * a inside the base. It can be used as a parser, but I 
 * strongly recommend developing a more sophisticated tool.*/
static int	get_idx(const char *base, char a)
{
	int	idx;
	int	out;

	out = -1;
	idx = 0;
	while (base[idx])
	{
		if (base[idx] == a)
		   out = idx;
		idx++;
	}
	return (out);
}

/*Allowing two representations for a same numberbase is a mess, so 
 * might just get the number written in one of them to process it
 * later. */
static char	*get_str_in_lowercase(char **s, int start, size_t len)
{
	char	*out;
	char	*aux;

	aux = ft_substr(*s, start, len + 1);
	out = aux;
	while (*aux)
	{
		*aux =ft_tolower(*aux);
		aux++;
	}
	return (out);
}

/* This gets pointed towards a comma, followed by an hexa 
 * number written as 0xFFFFFF or 0xffffff, and returns the
 * vaue in decimal.*/
int	get_color(char *str)
{
	int		color;
	char	*aux;
	char	*aux_free;
	int		power;

	if (*str != ',')
		return (0xFFFFFF);
	power = 5;
	aux = get_str_in_lowercase(&str, 3, 6);
	aux_free = aux;
	color = 0;
	while (*aux)
		color = color + (int)(get_idx("0123456789abcdef", *aux++) * pow(16, power--));
	free(aux_free);
	return (color);
}
