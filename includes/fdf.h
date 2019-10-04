/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 20:42:16 by lbellona          #+#    #+#             */
/*   Updated: 2019/10/04 22:17:40 by aashara-         ###   ########.fr       */
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
# define DEFAULT_COORDS_MALLOC 1000

typedef struct			s_point
{
	int					x;
	int					y;
	int					z;
}						t_point;

typedef struct			s_mlx_params
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;	
}						t_mlx_params;
typedef struct			s_map
{
	t_point				*inp_coords;
	t_point				*coords;
	int					width;
	int					height;
}						t_map;



/*
**	fdf.c
*/
void		pr_error(char *err_msg);
/*
**	read_map.c
*/
void		read_map(int fd, t_map *map);
void		parse_coords(char *line, t_point **coords, t_map *map);
void    	add_coords_2_arr(t_point **coords, char *line, int width, int height);
char		is_correct_char(char c);
void		check_map_width(int width, int height);
/*
**	draw_landscape.c
*/
void		draw_landscape(t_map *map, char *name);
void		init_win_params(t_mlx_params *mlx, char *name);
#endif
