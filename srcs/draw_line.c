/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:01:05 by aashara-          #+#    #+#             */
/*   Updated: 2019/10/12 20:36:18 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
			mlx->data_addr[++i] = 0;
			if (mlx->endian)
			{
				mlx->data_addr[i] = 0;
				mlx->data_addr[++i] = colour >> 16;
				mlx->data_addr[++i] = colour >> 8;
				mlx->data_addr[i] = colour;
			}
		}
	}
}

double	percent(int start, int end, int current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int		get_color(t_point current, t_point start, t_point end, t_point delta)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (current.colour == end.colour)
		return (current.colour);
	if (delta.x > delta.y)
		percentage = percent(start.x, end.x, current.x);
	else
		percentage = percent(start.y, end.y, current.y);
	red = get_light((start.colour >> 16) & 0xFF, (end.colour >> 16) & 0xFF,
	percentage);
	green = get_light((start.colour >> 8) & 0xFF, (end.colour >> 8) & 0xFF,
	percentage);
	blue = get_light(start.colour & 0xFF, end.colour & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}
