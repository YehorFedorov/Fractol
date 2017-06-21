/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 13:39:59 by efedorov          #+#    #+#             */
/*   Updated: 2017/03/24 13:40:00 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_c(t_mand_cube *cube, double x, double y)
{
	int		i;
	double	r;
	double	j;

	i = -1;
	r = (2 * x - 700) / 700 + x;
	j = (2 * y - 500) / 500 + y;
	cube->xmax = r + cube->x_pos;
	cube->ymax = j + cube->y_pos;
	while (++i < cube->iter)
	{
		cube->ymin = cube->ymax;
		cube->ymax = fabs((2 * cube->xmax * cube->ymax + j));
		cube->xmax = fabs((pow(cube->xmax, 2) - pow(cube->ymin, 2) + r));
		if ((pow(cube->xmax, 2) + pow(cube->ymax, 2)) > 4)
			break ;
	}
	if (i == 0)
		put_pxl_cube(cube, cube->x, cube->y, 0);
	else if (0 < i < cube->iter)
		put_pxl_cube(cube, cube->x, cube->y, cube->iter - (cube->iter - i));
	else
		put_pxl_cube(cube, cube->x, cube->y, 255);
}

void	ft_cube(t_mand_cube *cube)
{
	cube->y = -1;
	while (++cube->y < 500)
	{
		cube->x = -1;
		while (++cube->x < 700)
			check_c(cube, calc_x_c(cube->x, cube), calc_y_c(cube->y, cube));
	}
}

void	ft_draw_cube(t_mand_cube *cube)
{
	create_img_cube(cube);
	ft_cube(cube);
	destroy_img_cube(cube);
}

void	cube(void)
{
	t_mand_cube	*cube;

	cube = (t_mand_cube*)malloc(sizeof(t_mand_cube));
	if (ft_init_cube(cube) == 1)
		return ;
	mlx_hook(cube->win, 2, 3, &key_func_cube, cube);
	mlx_mouse_hook(cube->win, &cube_zoom, cube);
	mlx_hook(cube->win, 6, 64, &cube_coord, cube);
	mlx_loop_hook(cube->mlx, &loop_draw_cube, cube);
	mlx_loop(cube->mlx);
}
