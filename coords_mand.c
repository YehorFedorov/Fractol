/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords_mand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 13:41:16 by efedorov          #+#    #+#             */
/*   Updated: 2017/03/25 16:21:52 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mand_coord(int x, int y, t_mand *data)
{
	if (data->move == 0)
	{
		data->x_pos = calc_x(x, data);
		data->y_pos = calc_y(y, data);
	}
	return (0);
}

double	calc_x(int x, t_mand *data)
{
	double	dx;

	dx = (((data->x0 - data->x1) * x) / 700) + data->x1;
	return (dx);
}

double	calc_y(int y, t_mand *data)
{
	double	dy;

	dy = (((data->y0 - data->y1) * y) / 500) + data->y1;
	return (dy);
}

int		mand_zoom(int code, int x, int y, t_mand *data)
{
	double	dx;
	double	dy;

	dx = calc_x(x, data);
	dy = calc_y(y, data);
	if (code == 4)
	{
		data->x0 += ((dx - data->x0) / 2);
		data->x1 = dx + ((data->x1 - dx) / 2);
		data->y0 += ((dy - data->y0) / 2);
		data->y1 = dy + ((data->y1 - dy) / 2);
	}
	if (code == 5 && data->x0 <= 4)
	{
		data->x0 += (data->x0 - data->x1) / 2;
		data->x1 -= (data->x0 - data->x1) / 2;
		data->y0 += (data->y0 - data->y1) / 2;
		data->y1 -= (data->y0 - data->y1) / 2;
	}
	return (0);
}
