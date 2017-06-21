/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_cube.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 13:37:04 by efedorov          #+#    #+#             */
/*   Updated: 2017/03/24 13:37:05 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_init_cube(t_mand_cube *cube)
{
	if (!(cube->mlx = mlx_init()))
		return (1);
	cube->win = mlx_new_window(cube->mlx, 700, 500, "ship");
	cube->red = 15;
	cube->green = 95;
	cube->move = 1;
	cube->blue = 60;
	cube->iter = 100;
	cube->x0 = 1;
	cube->x1 = -2.5;
	cube->y0 = -1;
	cube->y1 = 1;
	return (0);
}

int		loop_draw_cube(t_mand_cube *cube)
{
	ft_draw_cube(cube);
	return (0);
}

void	put_pxl_cube(t_mand_cube *cube, int x, int y, int color)
{
	int	rgb[3];

	rgb[0] = color + cube->red < 255 ? color + cube->red : color;
	rgb[1] = color + cube->green < 255 ? color + cube->green : color;
	rgb[2] = color + cube->blue < 255 ? color + cube->blue : color;
	if (((x > 0) && (y > 0)) && ((x < 700) && (y < 500)))
	{
		cube->tmp[(x * 4) + (y * 700 * 4)] = rgb[2];
		cube->tmp[(x * 4) + (y * 700 * 4) + 1] = rgb[1];
		cube->tmp[(x * 4) + (y * 700 * 4) + 2] = rgb[0];
	}
}
