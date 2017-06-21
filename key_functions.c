/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 14:04:39 by efedorov          #+#    #+#             */
/*   Updated: 2017/03/05 15:28:22 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_func_color(int keycode, t_map *map)
{
	if (keycode == 15 && ((map->red + 15) <= 255))
		map->red += 15;
	else if (keycode == 5 && ((map->green + 16) <= 255))
		map->green += 15;
	else if (keycode == 11 && ((map->blue + 17) <= 255))
		map->blue += 15;
	else if (keycode == 14 && ((map->red - 15) >= 0))
		map->red -= 15;
	else if (keycode == 3 && ((map->green - 16) >= 0))
		map->green -= 15;
	else if (keycode == 9 && ((map->blue - 17) >= 0))
		map->blue -= 15;
	else if (keycode == 10)
	{
		map->red = 0;
		map->green = 0;
		map->blue = 0;
	}
	return (0);
}

void	hypno(t_map *map)
{
	if (map->col == 1)
		map->col = 0;
	else
		map->col = 1;
}

int		key_func(int keycode, t_map *map)
{
	static int	z1 = 1;

	if (keycode == 53)
		exit(0);
	else if (keycode == 27 && (z1 - 1) > 1 && z1--)
		map->zoom -= z1;
	else if (keycode == 24 && (z1 + 1) <= 2147483647 && z1++)
		map->zoom += z1;
	else if (keycode == 15 || keycode == 5 || keycode == 11 || keycode == 14 ||
			keycode == 10 || keycode == 9 || keycode == 3)
		key_func_color(keycode, map);
	else if (keycode == 69)
		hypno(map);
	else if (keycode == 1)
		cube();
	else if (keycode == 32)
		newton();
	else if (keycode == 38)
		julia();
	else if (keycode == 46)
		mandelbrot();
	return (0);
}
