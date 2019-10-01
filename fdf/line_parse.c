/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 20:11:07 by lbellona          #+#    #+#             */
/*   Updated: 2019/10/01 21:53:04 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

char				is_correct_char(char c)
{
	if (ft_isdigit(c) || c == '-')
		return (TRUE);
	return (FALSE);
}

void		get_3d_coords(char *line, t_3d_coords **coords, t_fdf *fdf)
{
	int		i;
	int		delta;
	char	str[100];

	i = -1;
	delta = 0;
	fdf->map.width = 0;
	while (line[++i])
	{
		if (is_correct_char(line[i]))
		{
			delta = i;
			while (is_correct_char(line[i]))
				++i;
			add_coords_2_lst(coords, ft_strncpy(str, line + delta, i - delta), fdf);
			--i;
			++fdf->map.width;
		}
		else if (line[i] != ' ')
			pr_error("map error");
	}
	++fdf->map.height;
}
