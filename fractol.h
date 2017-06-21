/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efedorov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 12:18:28 by efedorov          #+#    #+#             */
/*   Updated: 2017/03/05 15:59:22 by efedorov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include "mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>

typedef struct		s_mand
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*tmp;
	double		x_pos;
	double		y_pos;
	int			move;
	int			x;
	int			y;
	int			red;
	int			green;
	int			blue;
	int			iter;
	double		xmax;
	double		xmin;
	double		ymax;
	double		ymin;
	double		x0;
	double		x1;
	double		y0;
	double		y1;
}					t_mand;

typedef struct		s_mand_cube
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*tmp;
	double		x_pos;
	double		y_pos;
	int			x;
	int			y;
	int			move;
	int			red;
	int			green;
	int			blue;
	int			iter;
	double		xmax;
	double		ymax;
	double		ymin;
	double		x0;
	double		x1;
	double		y0;
	double		y1;
}					t_mand_cube;

typedef struct		s_newt
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*tmp;
	double		x_pos;
	double		y_pos;
	int			x;
	int			y;
	int			red;
	int			green;
	int			blue;
	int			iter;
	int			move;
	double		xmax;
	double		ymax;
	double		x0;
	double		x1;
	double		y0;
	double		y1;
}					t_newt;

typedef struct		s_j
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*tmp;
	double		x_pos;
	double		y_pos;
	double		x_c;
	double		y_c;
	int			x;
	int			y;
	int			move;
	int			red;
	int			green;
	int			blue;
	int			iter;
	double		xmax;
	double		xmin;
	double		ymax;
	double		ymin;
}					t_j;

typedef struct		s_map
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*tmp;
	int			red;
	int			green;
	int			blue;
	float		r;
	int			col;
	float		y_c;
	float		x_c;
	int			zoom;
}					t_map;

int					ft_init_map(t_map *map);
int					ft_init_data(t_mand *data);
int					ft_init_cube(t_mand_cube *cube);
void				put_pxl(t_map *map, int x, int y);
void				put_pxl_mand(t_mand *data, int x, int y, int color);
void				put_pxl_cube(t_mand_cube *cube, int x, int y, int color);
void				ft_draw(t_map *map);
void				ft_draw_mandle(t_mand *data);
void				ft_draw_cube(t_mand_cube *cube);
int					loop_draw(t_map *map);
int					loop_draw_mandle(t_mand *data);
void				create_img(t_map *map);
void				destroy_img(t_map *map);
void				create_img_mandl(t_mand *data);
void				destroy_img_mandl(t_mand *data);
int					key_func(int keycode, t_map *map);
int					key_func_mand(int keycode, t_mand *data);
void				mandelbrot(void);
void				circle(void);
void				julia(void);
void				cube(void);
int					ft_init_julia(t_j *tmp);
int					loop_draw_julia(t_j *tmp);
void				put_pxl_julia(t_j *tmp, int x, int y, int color);
int					key_func_color_cube(int keycode, t_mand_cube *cube);
void				create_img_julia(t_j *tmp);
void				destroy_img_julia(t_j *tmp);
void				create_img_cube(t_mand_cube *cube);
void				destroy_img_cube(t_mand_cube *cube);
int					key_func_julia(int keycode, t_j *tmp);
int					key_func_color_mand(int keycode, t_mand *data);
int					key_func_cube(int keycode, t_mand_cube *cube);
int					key_func_color_julia(int keycode, t_j *tmp);
int					find_coord(int x, int y, t_j *tmp);
void				ft_draw_julia(t_j *tmp);
void				ft_putchar(char c);
double				new_x(int x, t_j *tmp);
double				new_y(int y, t_j *tmp);
double				calc_x(int x, t_mand *data);
double				calc_y(int y, t_mand *data);
double				calc_x_c(int x, t_mand_cube *cube);
double				calc_y_c(int y, t_mand_cube *cube);
void				ft_putendl(char const *s);
void				ft_putstr(char const *s);
int					ft_strcmp(char *s1, char *s2);
int					mand_coord(int x, int y, t_mand *data);
int					cube_coord(int x, int y, t_mand_cube *cube);
int					julia_zoom(int code, int x, int y, t_j *tmp);
int					mand_zoom(int code, int x, int y, t_mand *data);
int					cube_zoom(int code, int x, int y, t_mand_cube *cube);
int					loop_draw_cube(t_mand_cube *cube);
void				ft_draw_newton(t_newt *new);
void				newton(void);
int					ft_init_newt(t_newt *new);
int					loop_draw_newt(t_newt *new);
void				put_pxl_newt(t_newt *new, int x, int y, int color);
int					key_func_newt(int keycode, t_newt *new);
int					key_func_color_newt(int keycode, t_newt *new);
int					newt_coord(int x, int y, t_newt *new);
double				calc_x_n(int x, t_newt *new);
double				calc_y_n(int y, t_newt *new);
int					newt_zoom(int code, int x, int y, t_newt *new);
void				create_img_newt(t_newt *new);
void				destroy_img_newt(t_newt *new);

#endif
