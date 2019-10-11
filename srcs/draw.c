/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:39:22 by aashara-          #+#    #+#             */
/*   Updated: 2019/10/11 18:18:50 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_img(t_mlx_params *mlx, t_map *map, t_point *coords)
{
	draw_map(mlx, map, coords);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr,
	0, 0);
	print_options(map, mlx);
}

void	draw_map(t_mlx_params *mlx, t_map *map, t_point *coords)
{
	int		i;
	t_point	p[2];

	i = -1;
	while (++i < map->height * map->width)
	{
		p[0].x = coords[i].x + map->offset.x;
		p[0].y = coords[i].y + map->offset.y;
		p[0].colour = coords[i].colour;
		if ((i + 1) % map->width != 0)
		{
			p[1].x = coords[i + 1].x + map->offset.x;
			p[1].y = coords[i + 1].y + map->offset.y;
			p[1].colour = coords[i + 1].colour;
			draw_line(mlx, p[0], p[1]);
		}
		if (i < (map->height - 1) * map->width)
		{
			p[1].x = coords[i + map->width].x + map->offset.x;
			p[1].y = coords[i + map->width].y + map->offset.y;
			p[1].colour = coords[i + map->width].colour;
			draw_line(mlx, p[0], p[1]);
		}
	}
}

void	draw_line(t_mlx_params *mlx, t_point start, t_point end)
{
	t_point	delta;
	t_point sign;
	t_point	cur;
	int		error[2];

	delta.x = abs(end.x - start.x);
	delta.y = abs(end.y - start.y);
	sign.x = (end.x - start.x) > 0 ? 1 : -1;
	sign.y = (end.y - start.y) > 0 ? 1 : -1;
	error[0] = delta.x - delta.y;
	cur = start;
	while (cur.x != end.x || cur.y != end.y)
	{
		put_pixel(mlx, cur.x, cur.y, get_color(cur, start, end, delta));
		if ((error[1] = 2 * error[0]) > -delta.y)
		{
			error[0] -= delta.y;
			cur.x += sign.x;
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			cur.y += sign.y;
		}
	}
}

void	put_pixel(t_mlx_params *mlx, int x, int y, int colour)
{
	int	i;
	int	bytes;

	if ((x < WIN_WIDTH) && (y < WIN_HEIGHT)
	&& (x >= 0) && (y >= 0))
	{
		bytes = mlx->bits_per_pixel / 8;
		i = bytes * (x + y * WIN_WIDTH);
		if (i >= 0 && i < (WIN_HEIGHT * WIN_WIDTH * bytes))
		{
			mlx->data_addr[i] = colour;
			mlx->data_addr[++i] = colour >> 8;
			mlx->data_addr[++i] = colour >> 16;
		}
	}
}
