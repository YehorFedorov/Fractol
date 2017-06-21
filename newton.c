/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 15:51:03 by efedorov          #+#    #+#             */
/*   Updated: 2017/03/24 15:51:03 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_n(t_newt *new, double x, double y)
{
	int		i;

	i = -1;
	new->xmax = new->x_pos;
	new->ymax = new->y_pos;
	while (++i < new->iter)
	{
		new->ymax = 2 * new->xmax * new->ymax + y;
		new->xmax = pow(new->xmax, 2) - pow(new->ymax, 2) + x;
		if (pow(new->ymax, 2) + pow(new->xmax, 2) > 16)
			break ;
	}
	if (0 <= i < new->iter)
		put_pxl_newt(new, new->x, new->y, new->iter - (new->iter - i));
	else
		put_pxl_newt(new, new->x, new->y, 0);
}

void	ft_newton(t_newt *new)
{
	new->y = -1;
	while (++new->y < 500)
	{
		new->x = -1;
		while (++new->x < 700)
			check_n(new, calc_x_n(new->x, new), calc_y_n(new->y, new));
	}
}

void	ft_draw_newton(t_newt *new)
{
	create_img_newt(new);
	ft_newton(new);
	destroy_img_newt(new);
}

void	newton(void)
{
	t_newt	*new;

	new = (t_newt*)malloc(sizeof(t_newt));
	if (ft_init_newt(new) == 1)
		return ;
	mlx_hook(new->win, 2, 3, &key_func_newt, new);
	mlx_mouse_hook(new->win, &newt_zoom, new);
	mlx_hook(new->win, 6, 64, &newt_coord, new);
	mlx_loop_hook(new->mlx, &loop_draw_newt, new);
	mlx_loop(new->mlx);
}
