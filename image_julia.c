/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_julia.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 12:55:21 by efedorov          #+#    #+#             */
/*   Updated: 2017/03/02 15:22:38 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	create_img_julia(t_j *tmp)
{
	int	size_line;
	int	bits_p_p;
	int	endian;

	tmp->img = mlx_new_image(tmp->mlx, 700, 500);
	tmp->tmp = mlx_get_data_addr(tmp->img, &bits_p_p, &size_line, &endian);
}

void	destroy_img_julia(t_j *tmp)
{
	mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->img, 0, 0);
	mlx_destroy_image(tmp->mlx, tmp->img);
}

void	create_img_newt(t_newt *new)
{
	int	size_line;
	int	bits_p_p;
	int	endian;

	new->img = mlx_new_image(new->mlx, 700, 500);
	new->tmp = mlx_get_data_addr(new->img, &bits_p_p, &size_line, &endian);
}

void	destroy_img_newt(t_newt *new)
{
	mlx_put_image_to_window(new->mlx, new->win, new->img, 0, 0);
	mlx_destroy_image(new->mlx, new->img);
}
