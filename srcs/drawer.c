#include "fdf.h"

void	draw_right_line(int	*mat[2], t_data *data)
{
	t_points	pnt;
	int			col;
	int			row;

	col = 0;
	row = data->row - 1;
	while (col < data->col - 1)
	{
		pnt.zi = mat[0][col];
		pnt.zf = mat[0][col + 1];
		pnt.clr_c = mat[1][col];
		pnt.clr_f = mat[1][col + 1];
		draw_iso_right(&pnt, data, &row, &col);
		col++;
	}
}

void	draw_rightop_line(t_mat *mat, t_data *data, int *row)
{
	t_points	pnt;
	int			col;

	col = 0;
	while (col < data->col)
	{
		pnt.zi = mat->mat_now[0][col];
		pnt.zf = mat->mat_prv[0][col];
		pnt.clr_c = mat->mat_now[1][col];
		pnt.clr_f = mat->mat_prv[1][col];
		draw_iso_top(&pnt, data, row, &col);
		if (col < data->col - 1)
		{
			pnt.zi = mat->mat_now[0][col];
			pnt.zf = mat->mat_now[0][col + 1];
			pnt.clr_c = mat->mat_now[1][col];
			pnt.clr_f = mat->mat_now[1][col + 1];
			draw_iso_right(&pnt, data, row, &col);
		}
		col++;
	}
}

/* Function that recieves the row and columns (from the map) and
 * computes the coordinates in isometric base that allow draw_line
 * to draw between the point (row, col) and (row, col +1), thus
 * the name, "iso right".
 * Coordinates in this function enter already in an isometric base,
 * but the coordinate system I use has its origin at the center
 * of the screen, so row and col have to be centered before
 * doing the math.*/
void	draw_iso_right(t_points *pnt, t_data *data, int *row, int *col)
{
	int	row_cent;
	int	col_cent;

	row_cent = *row - (data->row / 2);
	col_cent = *col - (data->col / 2);
	pnt->xi = (int)(data->s_fct
			* ((row_cent + col_cent) * cos (M_PI / 6)) + 1080);
	pnt->yi = (int)(data->s_fct
			* (-pnt->zi + (col_cent - row_cent) * sin (M_PI / 6)) + 680);
	pnt->xf = (int)(data->s_fct
			* ((row_cent + col_cent + 1) * cos (M_PI / 6)) + 1080);
	pnt->yf = (int)(data->s_fct
			* (-pnt->zf + (col_cent + 1 - row_cent) * sin (M_PI / 6)) + 680);
	draw_line(pnt, data);
}

/*Same as the previous function, but draws a line between
 * (row, col) and (row + 1, col). */
void	draw_iso_top(t_points *pnt, t_data *data, int *row, int *col)
{
	int	row_cent;
	int	col_cent;

	row_cent = *row - (data->row / 2);
	col_cent = *col - (data->col / 2);
	pnt->xi = (int)(data->s_fct
			* ((row_cent + col_cent) * cos (M_PI / 6)) + 1080);
	pnt->yi = (int)(data->s_fct
			* (-pnt->zi + (col_cent - row_cent) * sin(M_PI / 6)) + 680);
	pnt->xf = (int)(data->s_fct
			* ((row_cent + col_cent + 1) * cos (M_PI / 6)) + 1080);
	pnt->yf = (int)(data->s_fct
			* (-pnt->zf + (col_cent - row_cent - 1) * sin(M_PI / 6)) + 680);
	draw_line(pnt, data);
}

void	draw_image(int fd, t_data *data)
{
	int		row;
	char	*line;
	t_mat	row_mats;

	row = data->row - 1;
	init_row_matrix(data->col, &row_mats);
	give_scale_factor(data);
	while (row >= 0)
	{
		get_next_line(fd, &line);
		fill_row_matrix(&row_mats, &line, &row, &data->row);
		if (row == data->row - 1)
			draw_right_line(row_mats.mat_now, data);
		else
			draw_rightop_line(&row_mats, data, &row);
		row--;
	}
	free_matrix(&row_mats, row);
}
