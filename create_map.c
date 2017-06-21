/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 11:15:09 by efedorov          #+#    #+#             */
/*   Updated: 2017/03/05 15:49:44 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_circle_x(t_map *map, float x_c, float rad)
{
	float	x;
	float	y;

	x = x_c;
	rad *= map->zoom;
	while (x >= -960)
	{
		if (x >= 0)
		{
			y = sqrt(pow(rad, 2) - pow(x, 2));
			put_pxl(map, x + 1920 / 2, y + 1080 / 2);
			put_pxl(map, x + 1920 / 2, -y + 1080 / 2);
		}
		else
		{
			y = -sqrt(pow(rad, 2) - pow(x, 2));
			put_pxl(map, x + 1920 / 2, y + 1080 / 2);
			put_pxl(map, x + 1920 / 2, -y + 1080 / 2);
		}
		x--;
	}
}

void	draw_circle_y(t_map *map, float y_c, float rad)
{
	float	x;
	float	y;

	y = y_c;
	rad *= map->zoom;
	while (y >= -540)
	{
		if (y >= 0)
		{
			x = sqrt(pow(rad, 2) - pow(y, 2));
			put_pxl(map, x + 1920 / 2, y + 1080 / 2);
			put_pxl(map, -x + 1920 / 2, y + 1080 / 2);
		}
		else
		{
			x = -sqrt(pow(rad, 2) - pow(y, 2));
			put_pxl(map, x + 1920 / 2, y + 1080 / 2);
			put_pxl(map, -x + 1920 / 2, y + 1080 / 2);
		}
		y--;
	}
}

void	draw_circle(t_map *map, float x_c, float y_c, float rad)
{
	draw_circle_x(map, x_c, rad);
	draw_circle_y(map, y_c, rad);
}

void	drawing(t_map *map, float x_c, float y_c, float rad)
{
	if (rad <= 0.000000002)
		return ;
	draw_circle(map, x_c, y_c, rad);
	drawing(map, x_c, y_c, rad * 0.8);
}

void	ft_draw(t_map *map)
{
	create_img(map);
	drawing(map, map->x_c, map->y_c, map->r);
	destroy_img(map);
}
