/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_func_newt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 17:11:52 by efedorov          #+#    #+#             */
/*   Updated: 2017/03/24 17:11:53 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_func_newt(int keycode, t_newt *new)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 24 && (new->iter + 5) <= 700)
		new->iter += 5;
	else if (keycode == 27 && (new->iter - 5) >= 1)
		new->iter -= 5;
	else if (keycode == 15 || keycode == 5 || keycode == 11 || keycode == 14 ||
			keycode == 10 || keycode == 9 || keycode == 3)
		key_func_color_newt(keycode, new);
	else if (keycode == 48)
		new->move = new->move == 0 ? 1 : 0;
	else if (keycode == 1)
		cube();
	else if (keycode == 46)
		mandelbrot();
	else if (keycode == 38)
		julia();
	else if (keycode == 8)
		circle();
	return (0);
}

int		key_func_color_newt(int keycode, t_newt *new)
{
	if (keycode == 15 && ((new->red + 15) <= 255))
		new->red += 15;
	else if (keycode == 5 && ((new->green + 16) <= 255))
		new->green += 15;
	else if (keycode == 11 && ((new->blue + 17) <= 255))
		new->blue += 15;
	else if (keycode == 14 && ((new->red - 15) >= 0))
		new->red -= 15;
	else if (keycode == 3 && ((new->green - 16) >= 0))
		new->green -= 15;
	else if (keycode == 9 && ((new->blue - 17) >= 0))
		new->blue -= 15;
	else if (keycode == 10)
	{
		new->red = 0;
		new->green = 0;
		new->blue = 0;
	}
	return (0);
}
