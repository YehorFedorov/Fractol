/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 11:11:28 by efedorov          #+#    #+#             */
/*   Updated: 2017/03/01 14:37:01 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	create_img(t_map *map)
{
	int	size_line;
	int	bits_p_p;
	int	endian;

	map->img = mlx_new_image(map->mlx, 1920, 1080);
	map->tmp = mlx_get_data_addr(map->img, &bits_p_p, &size_line, &endian);
}

void	destroy_img(t_map *map)
{
	mlx_put_image_to_window(map->mlx, map->win, map->img, 0, 0);
	mlx_destroy_image(map->mlx, map->img);
}
