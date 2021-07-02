#include "libft.h"

int	ft_ishexa(char a)
{
	int	boolean;

	boolean = 0;
	if (ft_isdigit(a) || (a >= 'A' && a <= 'F')
		|| (a >= 'a' && a <= 'f'))
		boolean = 1;
	return (boolean);
}
