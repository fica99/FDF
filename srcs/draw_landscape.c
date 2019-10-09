/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_landscape.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 22:15:29 by aashara-          #+#    #+#             */
/*   Updated: 2019/10/09 21:54:15 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_landscape(t_map *map, char *name)
{
	t_fdf			fdf;
	t_mlx_params	mlx;

	init_win_params(&mlx, name);
	map->proj_type = PARALLEL;
	unset_angl(&map->angle_x, &map->angle_y);
	map->scale = scale_map(map->width, map->height);
	draw(map, &mlx);
	fdf.mlx = mlx;
	fdf.map = map;
	mlx_hook(mlx.win_ptr, 2, 0, (void*)&key_handler, &fdf);
	mlx_hook(mlx.win_ptr, 17, 0, (void*)&close_window, &fdf);
	mlx_loop(mlx.mlx_ptr);
}

void	draw(t_map *map, t_mlx_params *mlx)
{
	int	i;
	int	size;

	map->max.x = INT_MIN;
	map->max.y = INT_MIN;
	map->min.x = INT_MAX;
	map->min.y = INT_MAX;
	i = -1;
	size = map->width * map->height;
	while (++i < size)
	{
		map->coords[i].x = map->inp_coords[i].x * map->scale;
		map->coords[i].y = map->inp_coords[i].y * map->scale;
		map->coords[i].z = map->inp_coords[i].z * map->scale;
		map->coords[i].colour = map->inp_coords[i].colour;
		rotation_x(&(map->coords[i].y), &(map->coords[i].z), map->angle_x);
		rotation_y(&map->coords[i].x, &(map->coords[i].z), map->angle_y);
		if (map->proj_type == ISO)
			iso_proj(&map->coords[i].x, &map->coords[i].y, map->coords[i].z);
		min_max(map->coords[i].x, map->coords[i].y, map);
	}
	get_offset(map);
	put_img(mlx, map, map->coords);
}

void	rotation_x(int *y, int *z, double angle_x)
{
	int				y_copy;
	int				z_copy;

	y_copy = *y;
	z_copy = *z;
	*y = y_copy * cos(angle_x) + z_copy * sin(angle_x);
	*z = -y_copy * sin(angle_x) + z_copy * cos(angle_x);
}

void	rotation_y(int *x, int *z, double angle_y)
{
	int				x_copy;
	int				z_copy;

	x_copy = *x;
	z_copy = *z;
	*x = x_copy * cos(angle_y) + z_copy * sin(angle_y);
	*z = -x_copy * sin(angle_y) + z_copy * cos(angle_y);
}
