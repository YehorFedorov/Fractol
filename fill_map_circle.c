/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_circle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 15:13:01 by efedorov          #+#    #+#             */
/*   Updated: 2017/03/05 15:34:11 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_init_map(t_map *map)
{
	if (!(map->mlx = mlx_init()))
		return (1);
	map->win = mlx_new_window(map->mlx, 1920, 1080, "circle");
	map->red = 200;
	map->green = 200;
	map->blue = 0;
	map->r = 1920 / 2;
	map->x_c = 1920 / 2;
	map->y_c = 1080 / 2;
	map->col = 1;
	map->zoom = 1;
	return (0);
}

int		loop_draw(t_map *map)
{
	ft_draw(map);
	return (0);
}

void	hypno_col(t_map *map)
{
	static int	col;

	col = 0;
	if (map->blue >= 255 || map->red >= 255 || map->green >= 255)
		col = 0;
	map->red += col++;
	map->green += col++;
	map->blue += col++;
}

void	put_pxl(t_map *map, int x, int y)
{
	int			blue;
	int			green;
	int			red;

	if (map->col == 0)
		hypno_col(map);
	blue = map->blue;
	green = map->green;
	red = map->red;
	if (((x > 0) && (y > 0)) && ((x < 1920) && (y < 1080)))
	{
		map->tmp[(x * 4) + (y * 1920 * 4)] = blue;
		map->tmp[(x * 4) + (y * 1920 * 4) + 1] = green;
		map->tmp[(x * 4) + (y * 1920 * 4) + 2] = red;
	}
}
