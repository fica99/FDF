/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_landscape.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 22:15:29 by aashara-          #+#    #+#             */
/*   Updated: 2019/10/08 12:11:56 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_landscape(t_map *map, char *name)
{
	t_fdf			fdf;
	t_mlx_params	mlx;

	init_win_params(&mlx, name);
	draw(map, &mlx);
	fdf.mlx = mlx;
	fdf.map = map;
	mlx_hook(mlx.win_ptr, 2, 0, (void*)&key_handler, &fdf);
	mlx_hook(mlx.win_ptr, 17, 0, (void*)&close_window, &fdf);
	mlx_loop(mlx.mlx_ptr);
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
