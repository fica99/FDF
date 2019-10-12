/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_coords.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 16:05:42 by aashara-          #+#    #+#             */
/*   Updated: 2019/10/12 16:09:49 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		*transform_coords(t_point *coords, int height, int width)
{
	int		i;
	int		size;
	t_point	offset_map;

	if (!coords)
		return (NULL);
	i = -1;
	size = height * width;
	offset_map.x = width / 2;
	offset_map.y = height / 2;
	while (++i < size)
	{
		coords[i].x -= offset_map.x;
		coords[i].y -= offset_map.y;
	}
	return (coords);
}
