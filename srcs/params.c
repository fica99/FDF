/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:38:18 by aashara-          #+#    #+#             */
/*   Updated: 2019/10/07 22:35:06 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		scale_map(int width, int height)
{
	int				scale;

	if ((scale = fmax(WIN_WIDTH, WIN_HEIGHT) / fmax(width, height)) < 1)
		scale = 1;
	return (scale);
}

void	find_offset(t_map *map)
{
	map->offset.x = (WIN_WIDTH - map->width * map->scale) / 2;
	map->offset.y = (WIN_HEIGHT - map->height * map->scale) / 2;
}
