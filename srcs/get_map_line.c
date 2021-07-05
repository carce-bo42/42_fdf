#include "fdf.h"

void	init_row_matrix(int columns, t_mat *row_mats)
{
	row_mats->mat_now[0] = malloc(sizeof(int) * columns);
	row_mats->mat_now[1] = malloc(sizeof(int) * columns);
	row_mats->mat_prv[0] = malloc(sizeof(int) * columns);
	row_mats->mat_prv[1] = malloc(sizeof(int) * columns);
	row_mats->size = columns;
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

void	fill_row_matrix(t_mat *mat, char **line, int *row)
{
	char	*aux;

	aux = *line;
	if (*row == 0)
		line_to_matrix(mat->mat_now, line);
	else
	{
		rewrite_previous_line(mat);
		line_to_matrix(mat->mat_now, line);
	}
}

/*
void	print_matrix(t_mat *mat)
{
	int	i = 0;

	while (i < mat->size)
	{
		printf("mat[0][%i] = %i\n", i, mat->mat_now[0][i]);
		i++;
	}
	i = 0;
	while (i < mat->size)
	{
		printf("mat[1][%i] = %i\n", i, mat->mat_now[1][i]);
		i++;
	}
}*/

void	draw_image(int fd, t_data *data)
{
	int		row;
	char	*line;
	t_mat	row_mats;

	row = 0;
	init_row_matrix(data->col, &row_mats);
	give_scale_factor(data);
	while (row < data->row)
	{
		get_next_line(fd, &line);
		fill_row_matrix(&row_mats, &line, &row);
		if (row == 0)
			draw_right_line(row_mats.mat_now, data);
		else
			draw_rightop_line(&row_mats, data);
		row++;
	}
}
