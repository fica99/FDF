/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 20:42:16 by lbellona          #+#    #+#             */
/*   Updated: 2019/10/02 23:32:56 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <fcntl.h>
# include "mlx.h"
# include <math.h>
# include <errno.h>
# include "get_next_line.h"
# include <stdio.h>
# include <limits.h>

# define TRUE 1
# define FALSE 0
# define WIN_HEIGHT 1000
# define WIN_WIDTH 1000
# define START_MAP_SCALE_PERCENT 0.7
# define START_Z_SCALE 1
# define ISO 1
# define PARALLEL -1
# define POINT_COLOR 0xFFFFFF
# define TEXT_COLOR 0xFFFFFF
# define DEFAULT_COORDS_MALLOC 1000

typedef struct			s_point
{
	int					x;
	int					y;
	int					z;
}						t_point;

typedef struct			s_win_params
{
	void				*mlx_ptr;
	void				*win_ptr;
	int					width;
	int					height;
	int					color;
}						t_win_params;

typedef struct			s_img_params
{
	int					*ptr;
	int					*data;
	int					bpp;
	int					size_l;
	int					endian;
	int					width;
	int					height;
	t_point				dxy;
}						t_img_params;
typedef struct			s_map
{
	t_point				min;
	t_point				max;
	long long			avg_z;
	int					proj_type;
	int					scale;
	int					z_scale;
	int					x_offset;
	int					y_offset;
	t_point				*inp_coords;
	t_point				*coords;
	int					malloc_size;
	int					width;
	int					height;
	float				alpha_x;
	float				alpha_y;
}						t_map;

typedef struct			s_fdf
{
	t_map				map;
	t_win_params		win;
	t_img_params		img;
}						t_fdf;



/*
** ---------------------------- Print Functions --------------------------------
*/

void					print_curr_params(t_fdf *fdf);
int			main(int argc, char **argv);
void				pr_error(char *err_msg);
void        set_map(t_fdf *fdf, t_point **coords);
void		read_map(int fd, t_fdf *fdf);

void				add_coords_2_arr(t_point **coords,
									char *line, t_fdf *fdf);
void		get_3d_coords(char *line, t_point **coords, t_fdf *fdf);
char				is_correct_char(char c);
void				check_map_width(t_map *map);
void				find_min_max(int x, int y, t_map *map);
/*
** ------------------- Parameters Initialization Functions ---------------------
*/

void					init_win_params(t_win_params *win);
void					init_img_params(t_img_params *img, t_win_params *win);
void					init_map_params(t_map *map);
int						auto_map_scale(t_map *map);
void					cpy_inp_coords(t_fdf *fdf);
void					find_min_max(int x, int y, t_map *map);

/*
** ------------------- Coordinate Transformation Functions ---------------------
*/

void					scale_img(int *x, int *y, int *z, t_map *map);
void					rotate_by_x(int *y, int *z, float al);
void					rotate_by_y(int *x, int *z, float al);
void					iso(int *x, int *y, int z);
void					find_offset(t_img_params *img, t_map *map);

/*
** --------------------------- Draw Line Functions -----------------------------
*/

void					init_dl_params(t_point *delta, t_point *sign,
														t_point p1, t_point p0);
void					draw_line(t_img_params *img, t_point p0, t_point p1);
void					draw_point(t_img_params *img, t_point p);

/*
** ------------------------- Draw Landscape Functions --------------------------
*/

void					draw_landscape(t_fdf *fdf);
int						handle_key(int key, t_fdf *fdf);
void					draw(t_fdf *fdf);
void					put_2_img(t_img_params *img, t_map *map);
void					clean_img(t_img_params *img);

#endif
