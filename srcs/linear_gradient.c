/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear_gradient.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:58:17 by aashara-          #+#    #+#             */
/*   Updated: 2019/10/11 15:56:18 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
