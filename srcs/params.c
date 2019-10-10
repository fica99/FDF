/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:38:18 by aashara-          #+#    #+#             */
/*   Updated: 2019/10/10 23:00:59 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	min_max(int x, int y, t_map *map)
{
	if (map->min.x > x)
		map->min.x = x;
	if (map->min.y > y)
		map->min.y = y;
	if (map->max.x < x)
		map->max.x = x;
	if (map->max.y < y)
		map->max.y = y;
}

void	unset_angl(double *angle_x, double *angle_y)
{
	*angle_x = 0;
	*angle_y = 0;
}

void	iso_proj(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(PI_6);
	*y = -z + (previous_x + previous_y) * sin(PI_6);
}

int		scale_map(int width, int height)
{
	int	x;
	int	y;

	x = DEFAULT_SCALE * WIN_WIDTH / width;
	y = DEFAULT_SCALE * WIN_HEIGHT / height;
	return (fmax(x, y) > 1 ? fmax(x, y) : 1);
}

void	get_offset(t_map *map)
{
	map->offset.x = (WIN_WIDTH - abs(map->max.x - map->min.x)) / 2
	+ abs(map->min.x);
	map->offset.y = (WIN_HEIGHT - abs(map->max.y - map->min.y)) / 2
	+ abs(map->min.y);
}
