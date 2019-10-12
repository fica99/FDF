/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 16:35:07 by aashara-          #+#    #+#             */
/*   Updated: 2019/10/12 17:58:43 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		scale_map(int width, int height)
{
	int	x;
	int	y;
	int	max;

	x = DEFAULT_SCALE * WIN_WIDTH / width;
	y = DEFAULT_SCALE * WIN_HEIGHT / height;
	max = fmax(x, y);
	return (max > 1 ? max : 1);
}

t_point	get_offset(void)
{
	t_point	offset;

	offset.x = WIN_WIDTH / 2;
	offset.y = WIN_HEIGHT / 2;
	return (offset);
}

void	unset_angl(double *angle_x, double *angle_y, double *angle_z)
{
	*angle_x = 0;
	*angle_y = 0;
	*angle_z = 0;
}

t_point	calc_coord(int x, int y, t_map *map)
{
	int		index;
	t_point	point;

	index = x + y * map->width;
	point.x = map->inp_coords[index].x * map->scale;
	point.y = map->inp_coords[index].y * map->scale;
	point.z = map->inp_coords[index].z * map->scale;
	point.colour = map->inp_coords[index].colour;
	rotation_x(&point.y, &point.z, map->angle_x);
	rotation_y(&point.x, &point.z, map->angle_y);
	rotation_z(&point.x, &point.y, map->angle_z);
	if (map->proj_type == ISO)
		iso_proj(&point.x, &point.y, point.z);
	point.x += map->offset.x;
	point.y += map->offset.y;
	return (point);
}
