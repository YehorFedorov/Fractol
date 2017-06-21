/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 11:38:18 by efedorov          #+#    #+#             */
/*   Updated: 2017/03/05 15:58:48 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_check(char *argv)
{
	int		check;

	if (ft_strcmp(argv, "mandelbrot") == 0)
		check = 1;
	else if (ft_strcmp(argv, "circle") == 0)
		check = 2;
	else if (ft_strcmp(argv, "julia") == 0)
		check = 3;
	else if (ft_strcmp(argv, "ship") == 0)
		check = 4;
	else if (ft_strcmp(argv, "unknown") == 0)
		check = 5;
	else
	{
		ft_putstr("Wrong parameter! Possible variables:\n");
		ft_putendl("1)mandelbrot;\n2)circle;\n3)julia;\n4)ship;\n5)unknown;");
		exit(0);
	}
	return (check);
}

void	circle(void)
{
	t_map	*map;

	map = (t_map*)malloc(sizeof(t_map));
	if (ft_init_map(map) == 1)
		return ;
	mlx_hook(map->win, 2, 3, key_func, map);
	mlx_loop_hook(map->mlx, &loop_draw, map);
	mlx_loop(map->mlx);
}

void	julia(void)
{
	t_j		*tmp;

	tmp = (t_j*)malloc(sizeof(t_j));
	if (ft_init_julia(tmp) == 1)
		return ;
	mlx_hook(tmp->win, 2, 3, &key_func_julia, tmp);
	mlx_mouse_hook(tmp->win, &julia_zoom, tmp);
	mlx_hook(tmp->win, 6, 64, &find_coord, tmp);
	mlx_loop_hook(tmp->mlx, &loop_draw_julia, tmp);
	mlx_loop(tmp->mlx);
}

void	print_keys(void)
{
	ft_putendl("Keys to press for Mandelbrot, Julia, Ship and Unknown:");
	ft_putendl("1) +/- - for increase/reduce amount of iterations;");
	ft_putendl("2) M - Mandelbrot,J - Julia,C - Circle,S - Ship,U - Unknown;");
	ft_putendl("3) Mouse wheel for zoom in/out");
	ft_putendl("4) TAB - on/off mouse reaction");
	ft_putendl("5) R,G,B / E,F,V - change colours");
	ft_putendl("6) § - reset colours");
	ft_putendl("\nKeys to press for Circle:");
	ft_putendl("1) +/- - zoom in/out");
	ft_putendl("2) RIGHT + for psycho mod(not for epileptics)");
}

int		main(int argc, char **argv)
{
	int		check;

	if (argc != 2)
	{
		ft_putstr("Wrong amount of parameters!\n");
		ft_putendl("Right input: ./fractol \"your input\"");
		exit(0);
	}
	check = ft_check(argv[1]);
	print_keys();
	if (check == 1)
		mandelbrot();
	if (check == 2)
		circle();
	if (check == 3)
		julia();
	if (check == 4)
		cube();
	if (check == 5)
		newton();
	return (0);
}
