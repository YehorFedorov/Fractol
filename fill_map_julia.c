/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_julia.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 15:13:11 by efedorov          #+#    #+#             */
/*   Updated: 2017/03/05 15:23:01 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_init_julia(t_j *tmp)
{
	if (!(tmp->mlx = mlx_init()))
		return (1);
	tmp->win = mlx_new_window(tmp->mlx, 700, 500, "julia");
	tmp->move = 1;
	tmp->red = 10;
	tmp->blue = 60;
	tmp->red = 90;
	tmp->iter = 40;
	tmp->xmax = 2;
	tmp->xmin = -2;
	tmp->ymax = 2;
	tmp->ymin = -2;
	return (0);
}

int		loop_draw_julia(t_j *tmp)
{
	ft_draw_julia(tmp);
	return (0);
}

void	put_pxl_julia(t_j *tmp, int x, int y, int color)
{
	int	rgb[3];

	rgb[0] = color + tmp->red < 255 ? color + tmp->red : color;
	rgb[1] = color + tmp->green < 255 ? color + tmp->green : color;
	rgb[2] = color + tmp->blue < 255 ? color + tmp->blue : color;
	if (((x > 0) && (y > 0)) && ((x < 700) && (y < 500)))
	{
		tmp->tmp[(x * 4) + (y * 700 * 4)] = rgb[2];
		tmp->tmp[(x * 4) + (y * 700 * 4) + 1] = rgb[1];
		tmp->tmp[(x * 4) + (y * 700 * 4) + 2] = rgb[0];
	}
}
