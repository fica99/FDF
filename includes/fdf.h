/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 20:42:16 by lbellona          #+#    #+#             */
/*   Updated: 2019/10/12 15:25:15 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "libdar.h"
# include "libdir.h"
# include "libfifo.h"
# include "libhash.h"
# include "libstack.h"
# include "libstr.h"
# include <fcntl.h>
# include "mlx.h"
# include <math.h>
# include <errno.h>
# include <stdio.h>
# include <limits.h>

# define TRUE 10
# define K_ESC 53
# define K_W 13
# define K_S 1
# define K_A 0
# define K_D 2
# define K_Y 16
# define K_R 15
# define K_T 17
# define K_PLUS 24
# define K_MINUS 27
# define K_P 35
# define K_I 34
# define FALSE 0
# define WIN_HEIGHT 1000
# define WIN_WIDTH 1500
# define DEF_COORDS_SIZE 5000000
# define STANDART 0XB0E0E6
# define YELLOW 0XFFF000
# define RED 0XFF0000
# define DEFAULT_SCALE 0.5
# define PI_32 M_PI_4 / 8
# define PI_6 M_PI_2 / 3

typedef	enum			e_proj_type
{
	PARALLEL,
	ISO
}						t_proj_type;

typedef struct			s_point
{
	int					x;
	int					y;
	int					z;
	int					colour;
}						t_point;

typedef struct			s_mlx_params
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	char				*data_addr;
	int					size_line;
	int					endian;
	int					bits_per_pixel;
}						t_mlx_params;
typedef struct			s_map
{
	t_point				*coords;
	t_point				*inp_coords;
	t_point				offset;
	t_point				min;
	t_point				max;
	int					scale;
	t_proj_type			proj_type;
	double				angle_x;
	double				angle_y;
	int					width;
	int					height;
	int					colour;
}						t_map;

typedef struct			s_fdf
{
	t_map				*map;
	t_mlx_params		mlx;
}						t_fdf;
/*
**	fdf.c
*/
void					pr_error(char *err_msg);
/*
**	read_map.c
*/
void					read_map(int fd, t_map *map);
void					parse_coords(char *line, t_point **coords,
int *width, int *height);
void					add_coords_2_arr(t_point **coords, char *line,
int width, int height);
int						parse_colour(char *str, int *i);
void					check_map_width(int width, int height);
/*
**	draw_landscape.c
*/
void					draw_landscape(t_map *map, char *name);
void					draw(t_map *map, t_mlx_params *mlx);
void					rotation_x(int *y, int *z, double angle_x);
void					rotation_y(int *x, int *z, double angle_y);
/*
**	handlers.c
*/
void					key_handler(int key, t_fdf *fdf);
void					close_window(t_fdf *fdf);
/*
**	draw.c
*/
void					put_img(t_mlx_params *mlx, t_map *map, t_point *coords);
void					draw_map(t_mlx_params *mlx, t_map *map,
t_point *coords);
void					draw_line(t_mlx_params *mlx, t_point start,
t_point end);
void					put_pixel(t_mlx_params *mlx, int x, int y, int colour);
/*
**	params.c
*/
void					min_max(int x, int y, t_map *map);
void					unset_angl(double *angle_x, double *angle_y);
void					iso_proj(int *x, int *y, int z);
int						scale_map(int width, int height);
void					get_offset(t_map *map);
/*
**	linear_gradient.c
*/
double					percent(int start, int end, int current);
int						get_light(int start, int end, double percentage);
int						get_color(t_point current, t_point start, t_point end,
t_point delta);
/*
**	params_other.c
*/
void					init_win_params(t_mlx_params *mlx, char *name);
void					print_options(t_map *map, t_mlx_params *mlx);
void					print_keys(t_mlx_params *mlx);
#endif
