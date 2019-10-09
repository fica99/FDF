/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:39:22 by aashara-          #+#    #+#             */
/*   Updated: 2019/10/09 20:57:08 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_img(t_mlx_params *mlx, t_map *map, t_point *coords)
{
	draw_map(mlx, map, coords);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr,
	0, 0);
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

	init_draw_line_params(&delta, &sign, start, end);
	error[0] = delta.x - delta.y;
	draw_point(mlx, end);
	copy_point(&cur, start);
	while (cur.x != end.x || cur.y != end.y)
	{
		cur.colour = get_color(cur, start, end, delta);
		draw_point(mlx, cur);
		error[1] = 2 * error[0];
		if (error[1] > -delta.y)
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

void	draw_point(t_mlx_params *mlx, t_point point)
{
	int	i;

	i = point.x + point.y * WIN_WIDTH;
	if (i >= 0 && i < (WIN_HEIGHT * WIN_WIDTH)
	&& (point.x < WIN_WIDTH) && (point.y < WIN_HEIGHT)
	&& point.x >= 0 && point.y >= 0)
		mlx->data_addr[i] = point.colour;
}
