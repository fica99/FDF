/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:38:18 by aashara-          #+#    #+#             */
/*   Updated: 2019/10/08 18:55:54 by aashara-         ###   ########.fr       */
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

void	rotation_x(int *y, int *z, float angle_x)
{
	int				y_copy;
	int				z_copy;
	y_copy = *y;
	z_copy = *z;
	*y = y_copy * cos(angle_x) + z_copy * sin(angle_x);
	*z = -y_copy * sin(angle_x) + z_copy * cos(angle_x);
}

void	rotation_y(int *x, int *z, float angle_y)
{
	int				x_copy;
	int				z_copy;

	x_copy = *x;
	z_copy = *z;
	*x = x_copy * cos(angle_y) + z_copy * sin(angle_y);
	*z = -x_copy * sin(angle_y) + z_copy * cos(angle_y);
}

void	rotation_z(int *x, int *y, float angle_z)
{
	int				x_copy;
	int				y_copy;

	x_copy = *x;
	y_copy = *y;
	*x = x_copy * cos(angle_z) - y_copy * sin(angle_z);
	*y = -x_copy * sin(angle_z) + y_copy * cos(angle_z);
}
