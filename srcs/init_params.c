/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 20:48:11 by aashara-          #+#    #+#             */
/*   Updated: 2019/10/09 21:02:25 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_win_params(t_mlx_params *mlx, char *name)
{
	if (!(mlx->mlx_ptr = mlx_init()))
		pr_error("mlx_init error");
	if (!(mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
	name)))
		pr_error("mlx_new_window error");
	if (!(mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT)))
		pr_error("mlx_new_image error");
	if (!(mlx->data_addr = (int*)mlx_get_data_addr(mlx->img_ptr,
	&mlx->bits_per_pixel, &mlx->size_line, &mlx->endian)))
		pr_error("mlx_get_data_addr error");
}

void	copy_point(t_point *a, t_point b)
{
	a->x = b.x;
	a->y = b.y;
	a->z = b.z;
	a->colour = b.colour;
}

void	init_draw_line_params(t_point *delta, t_point *sign, t_point start,
t_point end)
{
	delta->x = abs(end.x - start.x);
	delta->y = abs(end.y - start.y);
	sign->x = (end.x - start.x) > 0 ? 1 : -1;
	sign->y = (end.y - start.y) > 0 ? 1 : -1;
}
