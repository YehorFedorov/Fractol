/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_mandle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 14:27:37 by efedorov          #+#    #+#             */
/*   Updated: 2017/03/05 15:23:09 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_init_data(t_mand *data)
{
	if (!(data->mlx = mlx_init()))
		return (1);
	data->win = mlx_new_window(data->mlx, 700, 500, "mandelbrot");
	data->iter = 100;
	data->move = 1;
	data->red = 10;
	data->green = 60;
	data->blue = 125;
	data->x0 = 1;
	data->x1 = -2.5;
	data->y0 = -1;
	data->y1 = 1;
	return (0);
}

int		loop_draw_mandle(t_mand *data)
{
	ft_draw_mandle(data);
	return (0);
}

void	put_pxl_mand(t_mand *data, int x, int y, int color)
{
	int rgb[3];

	rgb[0] = color + data->red < 255 ? color + data->red : color;
	rgb[1] = color + data->green < 255 ? color + data->green : color;
	rgb[2] = color + data->blue < 255 ? color + data->blue : color;
	if (((x > 0) && (y > 0)) && ((x < 700) && (y < 500)))
	{
		data->tmp[(x * 4) + (y * 700 * 4)] = rgb[2];
		data->tmp[(x * 4) + (y * 700 * 4) + 1] = rgb[1];
		data->tmp[(x * 4) + (y * 700 * 4) + 2] = rgb[0];
	}
}
