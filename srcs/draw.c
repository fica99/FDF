/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:39:22 by aashara-          #+#    #+#             */
/*   Updated: 2019/10/08 13:06:13 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			draw(t_map *map, t_mlx_params *mlx)
{
	int	i;
	int	size;

	i = -1;
	scale_map(map->width, map->height, &map->scale);
	get_offset(map);
	size = map->width * map->height;
	while (++i < size)
	{
		map->coords[i].x = map->inp_coords[i].x * map->scale.x + map->offset.x;
		map->coords[i].y = map->inp_coords[i].y * map->scale.y + map->offset.y;
		map->coords[i].z = map->inp_coords[i].z * map->scale.z;
	}
	put_img(mlx, map, map->coords);

}

void	put_img(t_mlx_params *mlx, t_map *map, t_point *coords)
{
	draw_map(mlx, map, coords);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr,
	0, 0);
}

void	draw_map(t_mlx_params *mlx, t_map *map, t_point *coords)
{
	int		i;
	int		size;
	t_point	p[2];

	i = -1;
	size = map->height * map->width;
	while (++i < size)
	{
		p[0].x = coords[i].x;
		p[0].y = coords[i].y;
		if ((i + 1) % map->width != 0)
		{
			p[1].x = coords[i + 1].x;
			p[1].y = coords[i + 1].y;
			draw_line(mlx, p[0], p[1]);
		}
		if (i < size - map->width)
		{
			p[1].x = coords[i + map->width].x;
			p[1].y = coords[i + map->width].y;
			draw_line(mlx, p[0], p[1]);
		}
	}
}

void	draw_line(t_mlx_params *mlx, t_point start, t_point end)
{
	t_point	delta;
	t_point sign;
	int		error[2];

	delta.x = abs(end.x - start.x);
	delta.y = abs(end.y - start.y);
	error[0] = delta.x - delta.y;
	sign.x = (end.x - start.x) > 0 ? 1 : -1;
	sign.y = (end.y - start.y) > 0 ? 1 : -1;
	draw_point(mlx, end);
	while (start.x != end.x || start.y != end.y)
	{
		draw_point(mlx, start);
		error[1] = 2 * error[0];
		if (error[1] > -delta.y)
		{
			error[0] -= delta.y;
			start.x += sign.x;
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			start.y += sign.y;
		}
	}
}

void	draw_point(t_mlx_params *mlx, t_point point)
{
	int	i;

	i = point.x + point.y * WIN_WIDTH;
	if (i >= 0 && i < (WIN_HEIGHT * WIN_WIDTH)
	&& (point.x <= WIN_WIDTH) && (point.y <= WIN_HEIGHT)
	&& point.x >= 0 && point.y >= 0)
		mlx->data_addr[i] = COLOUR_POINT;
}
