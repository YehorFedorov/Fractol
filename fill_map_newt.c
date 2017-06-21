/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_newt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 17:02:34 by efedorov          #+#    #+#             */
/*   Updated: 2017/03/24 17:02:34 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_init_newt(t_newt *new)
{
	if (!(new->mlx = mlx_init()))
		return (1);
	new->win = mlx_new_window(new->mlx, 700, 500, "newton");
	new->iter = 50;
	new->move = 1;
	new->red = 10;
	new->green = 60;
	new->blue = 125;
	new->x0 = 3;
	new->x1 = -3.5;
	new->y0 = -2;
	new->y1 = 2.5;
	return (0);
}

int		loop_draw_newt(t_newt *new)
{
	ft_draw_newton(new);
	return (0);
}

void	put_pxl_newt(t_newt *new, int x, int y, int color)
{
	int	rgb[3];

	rgb[0] = color + new->red < 255 ? color + new->red : color;
	rgb[1] = color + new->green < 255 ? color + new->green : color;
	rgb[2] = color + new->blue < 255 ? color + new->blue : color;
	if (((x > 0) && (y > 0)) && ((x < 700) && (y < 500)))
	{
		new->tmp[(x * 4) + (y * 700 * 4)] = rgb[2];
		new->tmp[(x * 4) + (y * 700 * 4) + 1] = rgb[1];
		new->tmp[(x * 4) + (y * 700 * 4) + 2] = rgb[0];
	}
}
