/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 20:42:16 by lbellona          #+#    #+#             */
/*   Updated: 2019/10/12 18:05:02 by aashara-         ###   ########.fr       */
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
# define K_Q 12
# define K_E 14
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
# define DEFAULT 0XB0E0E6
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
	t_point				*inp_coords;
	t_point				offset;
	int					scale;
	t_proj_type			proj_type;
	double				angle_x;
	double				angle_y;
	double				angle_z;
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
void					parse_coords(char *line, t_point **coords, t_map *map);
int						parse_colour(char *str, int *i);
void					add_coords_2_arr(t_point **coords, char *line, int *index, t_map *map);
void					check_map_width(int width, int height);
/*
**	init.c
*/
void					init_start_params(t_mlx_params *mlx, t_map *map, char *name);
void					init_win_params(t_mlx_params *mlx, char *name);
/*
**	transform_coords.c
*/
t_point					*transform_coords(t_point *coords, int height, int width);
/*
**	calc.c
*/
int						scale_map(int width, int height);
t_point					get_offset(void);
void					unset_angl(double *angle_x, double *angle_y, double *angle_z);
t_point					calc_coord(int x, int y, t_map *map);
/*
**	draw_space.c
*/
void					draw_space(t_map *map, char *name);
void					draw_map(t_mlx_params *mlx, t_map *map);
void					print_options(t_map *map, t_mlx_params *mlx);
void					print_keys(t_mlx_params *mlx);
/*
**	rotation.c
*/
void					rotation_x(int *y, int *z, double angle_x);
void					rotation_y(int *x, int *z, double angle_y);
void					rotation_z(int *x, int *y, double angle_z);
void					iso_proj(int *x, int *y, int z);
/*
**	draw_line.c
*/
void					draw_line(t_mlx_params *mlx, t_point start, t_point end);
void					put_pixel(t_mlx_params *mlx, int x, int y, int colour);
double					percent(int start, int end, int current);
int						get_light(int start, int end, double percentage);
int						get_color(t_point current, t_point start, t_point end, t_point delta);
/*
**	handlers.c
*/
void					close_window(void);
void					key_handler(int key, t_fdf *fdf);
#endif
