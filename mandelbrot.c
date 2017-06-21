/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 11:19:57 by efedorov          #+#    #+#             */
/*   Updated: 2017/03/05 15:58:39 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_m(t_mand *data, double x, double y)
{
	int		i;

	i = -1;
	data->xmax = data->x_pos;
	data->xmin = 0;
	data->ymax = data->y_pos;
	data->ymin = 0;
	while (++i < data->iter)
	{
		data->ymax = 2 * data->xmax * data->ymax + y;
		data->xmax = data->xmin - data->ymin + x;
		data->ymin = pow(data->ymax, 2);
		data->xmin = pow(data->xmax, 2);
		if (data->ymin + data->xmin > 4)
			break ;
	}
	if (i == 0)
		put_pxl_mand(data, data->x, data->y, 0);
	else if (0 < i < data->iter)
		put_pxl_mand(data, data->x, data->y, data->iter - (data->iter - i));
	else
		put_pxl_mand(data, data->x, data->y, 255);
}

void	ft_mandelbrot(t_mand *data)
{
	data->y = -1;
	while (++data->y < 500)
	{
		data->x = -1;
		while (++data->x < 700)
			check_m(data, calc_x(data->x, data), calc_y(data->y, data));
	}
}

void	ft_draw_mandle(t_mand *data)
{
	create_img_mandl(data);
	ft_mandelbrot(data);
	destroy_img_mandl(data);
}

void	mandelbrot(void)
{
	t_mand	*data;

	data = (t_mand*)malloc(sizeof(t_mand));
	if (ft_init_data(data) == 1)
		return ;
	mlx_hook(data->win, 2, 3, &key_func_mand, data);
	mlx_mouse_hook(data->win, &mand_zoom, data);
	mlx_hook(data->win, 6, 0, &mand_coord, data);
	mlx_loop_hook(data->mlx, &loop_draw_mandle, data);
	mlx_loop(data->mlx);
}
