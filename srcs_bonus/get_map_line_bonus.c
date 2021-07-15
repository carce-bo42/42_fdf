#include "fdf_bonus.h"

void	init_row_matrix(int columns, t_mat *row_mats)
{
	row_mats->mat_now[0] = malloc(sizeof(int) * columns);
	row_mats->mat_now[1] = malloc(sizeof(int) * columns);
	row_mats->mat_prv[0] = malloc(sizeof(int) * columns);
	row_mats->mat_prv[1] = malloc(sizeof(int) * columns);
	row_mats->size = columns;
}

void	free_matrix(t_mat *mat, int row)
{
	free(mat->mat_now[0]);
	free(mat->mat_now[1]);
	if (row != 1)
	{
		free(mat->mat_prv[0]);
		free(mat->mat_prv[1]);
	}
}

void	line_to_matrix(int **mat, char **line)
{
	char	*aux;
	int		i;

	aux = *line;
	i = 0;
	while (*aux)
	{
		mat[0][i] = ft_atoi(aux);
		aux = ft_atolstr(aux);
		mat[1][i] = get_color(aux);
		aux = ft_rgbstr(aux);
		i++;
	}
	free(*line);
}

void	rewrite_previous_line(t_mat *mat)
{
	int	i;

	i = 0;
	while (i < mat->size)
	{
		mat->mat_prv[0][i] = mat->mat_now[0][i];
		mat->mat_prv[1][i] = mat->mat_now[1][i];
		i++;
	}
}

void	fill_row_matrix(t_mat *mat, char **line, int *row, int *true_row)
{
	char	*aux;

	aux = *line;
	if (*row == *true_row)
		line_to_matrix(mat->mat_now, line);
	else
	{
		rewrite_previous_line(mat);
		line_to_matrix(mat->mat_now, line);
	}
}
