/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords_newt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 15:50:56 by efedorov          #+#    #+#             */
/*   Updated: 2017/03/24 15:50:57 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		newt_coord(int x, int y, t_newt *new)
{
	if (new->move == 0)
	{
		new->x_pos = calc_x_n(x, new);
		new->y_pos = calc_y_n(y, new);
	}
	return (0);
}

double	calc_x_n(int x, t_newt *new)
{
	double	dx;

	dx = (((new->x0 - new->x1) * x) / 700) + new->x1;
	return (dx);
}

double	calc_y_n(int y, t_newt *new)
{
	double	dy;

	dy = (((new->y0 - new->y1) * y) / 500) + new->y1;
	return (dy);
}

int		newt_zoom(int code, int x, int y, t_newt *new)
{
	double	dx;
	double	dy;

	dx = calc_x_n(x, new);
	dy = calc_y_n(y, new);
	if (code == 4)
	{
		new->x0 += ((dx - new->x0) / 2);
		new->x1 = dx + ((new->x1 - dx) / 2);
		new->y0 += ((dy - new->y0) / 2);
		new->y1 = dy + ((new->y1 - dy) / 2);
	}
	if (code == 5 && new->x0 <= 5)
	{
		new->x0 += (new->x0 - new->x1) / 2;
		new->x1 -= (new->x0 - new->x1) / 2;
		new->y0 += (new->y0 - new->y1) / 2;
		new->y1 -= (new->y0 - new->y1) / 2;
	}
	return (0);
}
