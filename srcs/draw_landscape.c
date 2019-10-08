/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_landscape.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 22:15:29 by aashara-          #+#    #+#             */
/*   Updated: 2019/10/08 22:12:18 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_landscape(t_map *map, char *name)
{
	t_fdf			fdf;
	t_mlx_params	mlx;

	init_win_params(&mlx, name);
	map->proj_type = PARALLEL;
	unset_angl(&map->angle_x, &map->angle_y, &map->angle_z);
	map->max.x = map->width;
	map->max.y = map->height;
	map->scale = scale_map(map->width, map->height);
	draw(map, &mlx);
	fdf.mlx = mlx;
	fdf.map = map;
	mlx_hook(mlx.win_ptr, 2, 0, (void*)&key_handler, &fdf);
	mlx_hook(mlx.win_ptr, 17, 0, (void*)&close_window, &fdf);
	mlx_loop(mlx.mlx_ptr);
}

void			draw(t_map *map, t_mlx_params *mlx)
{
	int	i;
	int	size;

	i = -1;
	size = map->width * map->height;
	while (++i < size)
	{
		map->coords[i].x = map->inp_coords[i].x * map->scale;
		map->coords[i].y = map->inp_coords[i].y * map->scale;
		map->coords[i].z = map->inp_coords[i].z * map->scale;
		map->coords[i].colour = map->inp_coords[i].colour;
		if (map->proj_type == ISO)
			iso_proj(&map->coords[i].x, &map->coords[i].y, map->coords[i].z);
		rotation_x(&(map->coords[i].y), &(map->coords[i].z), map->angle_x);
		rotation_y(&map->coords[i].x, &(map->coords[i].z), map->angle_y);
		rotation_z(&(map->coords[i]).x,&(map->coords[i].y), map->angle_z);
		min_max(&(map->coords[i]).x,&(map->coords[i].y), map);
	}
	//get_offset(map);
	put_img(mlx, map, map->coords);
}

void				init_win_params(t_mlx_params *mlx, char *name)
{
	int	bits_per_pixel;
	int	size_line;
	int	endian;

	if (!(mlx->mlx_ptr = mlx_init()))
		pr_error("mlx_init error");
	if (!(mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, name)))
		pr_error("mlx_new_window error");
	if (!(mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT)))
		pr_error("mlx_new_image error");
	if (!(mlx->data_addr = (int*)mlx_get_data_addr(mlx->img_ptr, &bits_per_pixel,
	&size_line, &endian)))
		pr_error("mlx_get_data_addr error");
}
