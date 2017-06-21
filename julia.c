/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 12:48:53 by efedorov          #+#    #+#             */
/*   Updated: 2017/03/05 14:18:08 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_j(t_j *tmp, double x, double y)
{
	int		i;

	i = -1;
	tmp->x_c = 0;
	tmp->y_c = 0;
	while (++i < tmp->iter)
	{
		tmp->x_c = x;
		tmp->y_c = y;
		x = pow(tmp->x_c, 2) - pow(tmp->y_c, 2) + tmp->x_pos;
		y = 2 * tmp->x_c * tmp->y_c + tmp->y_pos;
		if ((pow(tmp->x_c, 2) + pow(tmp->y_c, 2)) > 4)
			break ;
	}
	if (i == 0)
		put_pxl_julia(tmp, tmp->x, tmp->y, 255);
	else if (0 < i < tmp->iter)
		put_pxl_julia(tmp, tmp->x, tmp->y, tmp->iter - (tmp->iter - i));
	else
		put_pxl_julia(tmp, tmp->x, tmp->y, 0);
}

void	ft_julia(t_j *tmp)
{
	tmp[0].y = -1;
	while (++tmp[0].y < 500)
	{
		tmp[0].x = -1;
		while (++tmp->x < 700)
			check_j(tmp, new_x(tmp[0].x, tmp), new_y(tmp[0].y, tmp));
	}
}

void	ft_draw_julia(t_j *tmp)
{
	create_img_julia(tmp);
	ft_julia(tmp);
	destroy_img_julia(tmp);
}
