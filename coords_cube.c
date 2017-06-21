/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords_cube.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 13:45:56 by efedorov          #+#    #+#             */
/*   Updated: 2017/03/24 13:45:56 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		cube_coord(int x, int y, t_mand_cube *cube)
{
	if (cube->move == 1)
	{
		cube->x_pos = calc_x_c(x, cube);
		cube->y_pos = calc_y_c(y, cube);
	}
	return (0);
}

double	calc_x_c(int x, t_mand_cube *cube)
{
	double	dx;

	dx = (((cube->x0 - cube->x1) * x) / 700) + cube->x1;
	return (dx);
}

double	calc_y_c(int y, t_mand_cube *cube)
{
	double	dy;

	dy = (((cube->y0 - cube->y1) * y) / 500) + cube->y1;
	return (dy);
}

int		cube_zoom(int code, int x, int y, t_mand_cube *cube)
{
	double	dx;
	double	dy;

	dx = calc_x_c(x, cube);
	dy = calc_y_c(y, cube);
	if (code == 4)
	{
		cube->x0 += ((dx - cube->x0) / 2);
		cube->x1 = dx + ((cube->x1 - dx) / 2);
		cube->y0 += ((dy - cube->y0) / 2);
		cube->y1 = dy + ((cube->y1 - dy) / 2);
	}
	if (code == 5 && cube->x0 <= 5)
	{
		cube->x0 += (cube->x0 - cube->x1) / 2;
		cube->x1 -= (cube->x0 - cube->x1) / 2;
		cube->y0 += (cube->y0 - cube->y1) / 2;
		cube->y1 -= (cube->y0 - cube->y1) / 2;
	}
	return (0);
}
