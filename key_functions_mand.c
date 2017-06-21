/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions_mand.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 15:14:09 by efedorov          #+#    #+#             */
/*   Updated: 2017/03/05 15:24:31 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_func_mand(int keycode, t_mand *data)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 24 && (data->iter + 5) <= 450)
		data->iter += 5;
	else if (keycode == 27 && (data->iter - 5) >= 1)
		data->iter -= 5;
	else if (keycode == 15 || keycode == 5 || keycode == 11 || keycode == 14 ||
			keycode == 10 || keycode == 9 || keycode == 3)
		key_func_color_mand(keycode, data);
	else if (keycode == 48)
		data->move = data->move == 0 ? 1 : 0;
	else if (keycode == 1)
		cube();
	else if (keycode == 32)
		newton();
	else if (keycode == 38)
		julia();
	else if (keycode == 8)
		circle();
	return (0);
}

int		key_func_cube(int keycode, t_mand_cube *cube)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 24 && (cube->iter + 5) <= 450)
		cube->iter += 5;
	else if (keycode == 27 && (cube->iter - 5) >= 1)
		cube->iter -= 5;
	else if (keycode == 15 || keycode == 5 || keycode == 11 || keycode == 14 ||
			keycode == 10 || keycode == 9 || keycode == 3)
		key_func_color_cube(keycode, cube);
	else if (keycode == 48)
		cube->move = cube->move == 0 ? 1 : 0;
	else if (keycode == 46)
		mandelbrot();
	else if (keycode == 32)
		newton();
	else if (keycode == 38)
		julia();
	else if (keycode == 8)
		circle();
	return (0);
}

int		key_func_color_cube(int keycode, t_mand_cube *cube)
{
	if (keycode == 15 && ((cube->red + 15) <= 255))
		cube->red += 15;
	else if (keycode == 5 && ((cube->green + 16) <= 255))
		cube->green += 15;
	else if (keycode == 11 && ((cube->blue + 17) <= 255))
		cube->blue += 15;
	else if (keycode == 14 && ((cube->red - 15) >= 0))
		cube->red -= 15;
	else if (keycode == 3 && ((cube->green - 16) >= 0))
		cube->green -= 15;
	else if (keycode == 9 && ((cube->blue - 17) >= 0))
		cube->blue -= 15;
	else if (keycode == 10)
	{
		cube->red = 0;
		cube->green = 0;
		cube->blue = 0;
	}
	return (0);
}

int		key_func_color_mand(int keycode, t_mand *data)
{
	if (keycode == 15 && ((data->red + 15) <= 255))
		data->red += 15;
	else if (keycode == 5 && ((data->green + 16) <= 255))
		data->green += 15;
	else if (keycode == 11 && ((data->blue + 17) <= 255))
		data->blue += 15;
	else if (keycode == 14 && ((data->red - 15) >= 0))
		data->red -= 15;
	else if (keycode == 3 && ((data->green - 16) >= 0))
		data->green -= 15;
	else if (keycode == 9 && ((data->blue - 17) >= 0))
		data->blue -= 15;
	else if (keycode == 10)
	{
		data->red = 0;
		data->green = 0;
		data->blue = 0;
	}
	return (0);
}
