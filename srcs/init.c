/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 20:48:11 by aashara-          #+#    #+#             */
/*   Updated: 2019/10/12 17:26:05 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_start_params(t_mlx_params *mlx, t_map *map, char *name)
{
	init_win_params(mlx, name);
	map->proj_type = PARALLEL;
	unset_angl(&map->angle_x, &map->angle_y, &map->angle_z);
	map->scale = scale_map(map->width, map->height);
	map->offset = get_offset();
	map->colour = DEFAULT;
}

void	init_win_params(t_mlx_params *mlx, char *name)
{
	if (!(mlx->mlx_ptr = mlx_init()))
		pr_error("mlx_init error");
	if (!(mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
	name)))
		pr_error("mlx_new_window error");
	if (!(mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT)))
		pr_error("mlx_new_image error");
	if (!(mlx->data_addr = (char*)mlx_get_data_addr(mlx->img_ptr,
	&mlx->bits_per_pixel, &mlx->size_line, &mlx->endian)))
		pr_error("mlx_get_data_addr error");
}
