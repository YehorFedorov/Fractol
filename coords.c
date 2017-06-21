/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 13:49:34 by efedorov          #+#    #+#             */
/*   Updated: 2017/03/25 16:35:59 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		find_coord(int x, int y, t_j *tmp)
{
	if (tmp->move == 0)
	{
		tmp->x_pos = new_x(x, tmp);
		tmp->y_pos = new_y(y, tmp);
	}
	return (0);
}

double	new_x(int x, t_j *tmp)
{
	double		dx;

	dx = (((tmp->xmax - tmp->xmin) * x) / 700) + tmp->xmin;
	return (dx);
}

double	new_y(int y, t_j *tmp)
{
	double		dy;

	dy = (((tmp->ymax - tmp->ymin) * y) / 500) + tmp->ymin;
	return (dy);
}

int		julia_zoom(int code, int x, int y, t_j *tmp)
{
	double	dx;
	double	dy;

	dx = new_x(x, tmp);
	dy = new_y(y, tmp);
	if (code == 4)
	{
		tmp->xmax += ((dx - tmp->xmax) / 2);
		tmp->xmin = dx + ((tmp->xmin - dx) / 2);
		tmp->ymax += ((dy - tmp->ymax) / 2);
		tmp->ymin = dy + ((tmp->ymin - dy) / 2);
	}
	if (code == 5 && tmp->xmax <= 5)
	{
		tmp->xmax += (tmp->xmax - tmp->xmin) / 2;
		tmp->xmin -= (tmp->xmax - tmp->xmin) / 2;
		tmp->ymax += (tmp->ymax - tmp->ymin) / 2;
		tmp->ymin -= (tmp->ymax - tmp->ymin) / 2;
	}
	return (0);
}
