/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_landscape.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 22:15:29 by aashara-          #+#    #+#             */
/*   Updated: 2019/10/06 21:07:45 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_landscape(t_map *map, char *name)
{
	t_mlx_params	mlx;
	int				i;
	int				size;
	t_point			start;	
	t_point			end;

	init_win_params(&mlx, name);
	i = -1;
	size = map->height * map->width;
	start.x = 500;
	start.y = 500;
	end.x = 1000;
	end.y = 0;
	draw_line(&mlx, start, end);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img_ptr, 0, 0);
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

void	draw_line(t_mlx_params *mlx, t_point start, t_point end)
{
	t_point	delta;
	t_point sign;
	int		error;
	int		error2;

	delta.x = abs(end.x - start.x);
	delta.y = abs(end.y - start.y);
	error = delta.x - delta.y;
	sign.x = (end.x - start.x) > 0 ? 1 : -1;
	sign.y = (end.y - start.y) > 0 ? 1 : -1;
	draw_point(mlx, end);
	while(start.x != end.x || start.y != end.y)
	{
		draw_point(mlx, start);
		if ((error2 = 2 * error) > -delta.y)
		{
			error -= delta.y;
			start.x += sign.x;
		}
		if (error2 < delta.x)
		{
			error += delta.x;
			start.y += sign.y;
		}
	}
}

void	draw_point(t_mlx_params *mlx, t_point point)
{
	int	i;

	i = point.x + point.y * WIN_WIDTH;
	if (i >= 0 && i < (WIN_HEIGHT * WIN_WIDTH)
	&& (point.x < WIN_WIDTH) && (point.y < WIN_HEIGHT)
	&& point.x >= 0 && point.y >= 0)
		mlx->data_addr[i] = COLOUR_POINT; 
}