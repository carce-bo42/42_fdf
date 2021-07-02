#include "libft.h"

int	ft_iscoma(char a)
{
	int	boolean;

	boolean = 0;
	if (a == ',')
		boolean = 1;
	return (boolean);
}
