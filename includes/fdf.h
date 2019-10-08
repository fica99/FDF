/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 20:42:16 by lbellona          #+#    #+#             */
/*   Updated: 2019/10/08 23:02:00 by aashara-         ###   ########.fr       */
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

# define TRUE 1
# define FALSE 0
# define WIN_HEIGHT 1000
# define WIN_WIDTH 1500
# define DEFAULT_COORDS_MALLOC 1000
# define COLOUR_POINT 0XFFFFFF
# define DEFAULT_SCALE 0.5
# define PI_32 M_PI_4 / 8

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
	int					*data_addr;
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
	double				angle_z;
	int					width;
	int					height;
}						t_map;

typedef struct 			s_fdf
{
	t_map				*map;
	t_mlx_params		mlx;
}						t_fdf;


/*
**	fdf.c
*/
void		pr_error(char *err_msg);
/*
**	read_map.c
*/
void		read_map(int fd, t_map *map);
void		parse_coords(char *line, t_point **coords, t_map *map);
void		add_coords_2_arr(t_point **coords, char *line, int width, int height);
char		is_correct_char(char c);
void		check_map_width(int width, int height);
/*
**	draw_landscape.c
*/
void		draw_landscape(t_map *map, char *name);
void		draw(t_map *map, t_mlx_params *mlx);
void		init_win_params(t_mlx_params *mlx, char *name);
/*
**	handlers.c
*/
void		key_handler(int key, t_fdf *fdf);
void		close_window(t_fdf *fdf);
/*
**	draw.c
*/
void		put_img(t_mlx_params *mlx, t_map *map, t_point *coords);
void		draw_map(t_mlx_params *mlx, t_map *map, t_point *coords);
void		draw_line(t_mlx_params *mlx, t_point start, t_point end);
void		draw_point(t_mlx_params *mlx, t_point point);
/*
**	params.c
*/
int			scale_map(int width, int height);
void		get_offset(t_map *map);
void		min_max(int *x, int *y, t_map *map);
void		unset_angl(double *angle_x, double *angle_y, double *angle_z);
void		iso_proj(int *x, int *y, int z);
/*
**	rotation.c
*/
void		rotation_x(int *y, int *z, float angle_x);
void		rotation_y(int *x, int *z, float angle_y);
void		rotation_z(int *x, int *y, float angle_z);
#endif
