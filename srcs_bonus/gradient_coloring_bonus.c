#include "fdf_bonus.h"

void	init_color_grad(t_draw *utils, t_points *pnt)
{
	utils->clr_i = pnt->clr_c;
	utils->x_i = pnt->xi;
	utils->y_i = pnt->yi;
}

static double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	if (distance == 0)
		return (1);
	else
		return (placement / distance);
}

static int	get_light(int start, int end, double pctg)
{
	return ((int)((1 - pctg) * start + pctg * end));
}

int	get_pixel_color(t_draw *utils, t_points *pnt)
{
	int		red;
	int		green;
	int		blue;
	double	pctg;

	if (pnt->clr_c == pnt->clr_f)
		return (pnt->clr_c);
	if (utils->dx > utils->dy)
		pctg = percent(utils->x_i, pnt->xf, pnt->xi);
	else
		pctg = percent(utils->y_i, pnt->yf, pnt->yi);
	red = get_light((utils->clr_i >> 16)
			& 0xFF, (pnt->clr_f >> 16) & 0xFF, pctg);
	green = get_light((utils->clr_i >> 8)
			& 0xFF, (pnt->clr_f >> 8) & 0xFF, pctg);
	blue = get_light(utils->clr_i & 0xFF, pnt->clr_f & 0xFF, pctg);
	return ((red << 16) | (green << 8) | blue);
}
