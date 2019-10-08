/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:38:18 by aashara-          #+#    #+#             */
/*   Updated: 2019/10/08 20:13:09 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		scale_map(int width, int height)
{
	int	x;
	int	y;

	x = DEFAULT_SCALE * WIN_WIDTH / width;
	y = DEFAULT_SCALE * WIN_HEIGHT / height;
	return (fmax(x, y) > 1 ? fmax(x,y) : 1);
}

void	get_offset(t_map *map)
{
	map->offset.x = (WIN_WIDTH - (map->width - 1) * map->scale) / 2;
	map->offset.y = (WIN_HEIGHT - (map->height - 1) * map->scale) / 2;
}

void	unset_angl(double *angle_x, double *angle_y, double *angle_z)
{
	*angle_x = 0;
	*angle_y = 0;
	*angle_z = 0;
}

void	iso_proj(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}
