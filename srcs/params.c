/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:38:18 by aashara-          #+#    #+#             */
/*   Updated: 2019/10/08 13:09:16 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scale_map(int width, int height, t_point *scale)
{
	if ((scale->x = DEFAULT_SCALE * WIN_WIDTH / width) < 1)
		scale->x = 1;
	if ((scale->y = DEFAULT_SCALE * WIN_HEIGHT / height) < 1)
		scale->y = 1;
	scale->z = 1;
}

void	get_offset(t_map *map)
{
	map->offset.x = (WIN_WIDTH - map->width * map->scale.x) / 2;
	map->offset.y = (WIN_HEIGHT - map->height * map->scale.y) / 2;
}
