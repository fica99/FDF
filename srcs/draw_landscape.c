/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_landscape.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 22:15:29 by aashara-          #+#    #+#             */
/*   Updated: 2019/10/04 22:19:02 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_landscape(t_map *map, char *name)
{
	t_mlx_params	mlx;

    (void)map;	
	init_win_params(&mlx, name);
	mlx_loop(mlx.mlx_ptr);
}

void				init_win_params(t_mlx_params *mlx, char *name)
{
	if (!(mlx->mlx_ptr = mlx_init()))
		pr_error("mlx_init error");
	if (!(mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, name)))
		pr_error("mlx_new_window error");
	if (!(mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT)))
		pr_error("mlx_new_image error");
}