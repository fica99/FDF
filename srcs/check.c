/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 20:08:52 by aashara-          #+#    #+#             */
/*   Updated: 2019/10/02 21:09:01 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char				is_correct_char(char c)
{
	if (ft_isdigit(c) || c == '-')
		return (TRUE);
	return (FALSE);
}

void				check_map_width(t_map *map)
{
	static int		old_width;

	if (map->height == 1)
		old_width = map->width;
	else if (old_width != map->width)
		pr_error("wrong map width");
}

void				find_min_max(int x, int y, t_map *map)
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