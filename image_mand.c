/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_mand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 14:41:41 by efedorov          #+#    #+#             */
/*   Updated: 2017/03/02 12:56:46 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	create_img_mandl(t_mand *data)
{
	int	size_line;
	int	bits_p_p;
	int	endian;

	data->img = mlx_new_image(data->mlx, 700, 500);
	data->tmp = mlx_get_data_addr(data->img, &bits_p_p, &size_line, &endian);
}

void	destroy_img_mandl(t_mand *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_destroy_image(data->mlx, data->img);
}

void	create_img_cube(t_mand_cube *cube)
{
	int	size_line;
	int	bits_p_p;
	int	endian;

	cube->img = mlx_new_image(cube->mlx, 700, 500);
	cube->tmp = mlx_get_data_addr(cube->img, &bits_p_p, &size_line, &endian);
}

void	destroy_img_cube(t_mand_cube *cube)
{
	mlx_put_image_to_window(cube->mlx, cube->win, cube->img, 0, 0);
	mlx_destroy_image(cube->mlx, cube->img);
}
