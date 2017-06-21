/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_function_julia.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 13:07:05 by efedorov          #+#    #+#             */
/*   Updated: 2017/03/05 15:20:04 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_func_julia(int keycode, t_j *tmp)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 24 && (tmp->iter + 5) <= 450)
		tmp->iter += 5;
	else if (keycode == 27 && (tmp->iter - 5) >= 1)
		tmp->iter -= 5;
	else if (keycode == 15 || keycode == 5 || keycode == 11 || keycode == 14 ||
			keycode == 10 || keycode == 9 || keycode == 3)
		key_func_color_julia(keycode, tmp);
	else if (keycode == 48)
		tmp->move = tmp->move == 0 ? 1 : 0;
	else if (keycode == 46)
		mandelbrot();
	else if (keycode == 8)
		circle();
	else if (keycode == 32)
		newton();
	else if (keycode == 1)
		cube();
	return (0);
}

int		key_func_color_julia(int keycode, t_j *tmp)
{
	if (keycode == 15 && ((tmp->red + 15) <= 255))
		tmp->red += 15;
	else if (keycode == 5 && ((tmp->green + 16) <= 255))
		tmp->green += 15;
	else if (keycode == 11 && ((tmp->blue + 17) <= 255))
		tmp->blue += 15;
	else if (keycode == 14 && ((tmp->red - 15) >= 0))
		tmp->red -= 15;
	else if (keycode == 3 && ((tmp->green - 16) >= 0))
		tmp->green -= 15;
	else if (keycode == 9 && ((tmp->blue - 17) >= 0))
		tmp->blue -= 15;
	else if (keycode == 10)
	{
		tmp->red = 0;
		tmp->green = 0;
		tmp->blue = 0;
	}
	return (0);
}
