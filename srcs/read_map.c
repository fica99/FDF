/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 20:27:15 by aashara-          #+#    #+#             */
/*   Updated: 2019/10/09 21:05:18 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	read_map(int fd, t_map *map)
{
	char	*line;
	t_point	*coords;

	map->height = 0;
	coords = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		parse_coords(line, &coords, map);
		check_map_width(map->width, map->height);
		ft_strdel(&line);
	}
	if (!coords)
		pr_error("wrong line from file");
	map->inp_coords = coords;
	if (!(map->coords = (t_point*)malloc(sizeof(t_point) *
	map->height * map->width)))
		pr_error("memory allocation error");
}

void	parse_coords(char *line, t_point **coords, t_map *map)
{
	int		i;
	int		delta;

	i = -1;
	map->width = 0;
	while (line[++i])
	{
		if (line[i] == ' ')
			continue ;
		if (is_correct_char(line[i]))
		{
			delta = i;
			while (is_correct_char(line[i]))
				++i;
			add_coords_2_arr(coords, line + delta, map->width, map->height);
			--i;
			++map->width;
		}
		else
			pr_error("map error");
	}
	++map->height;
}

void	add_coords_2_arr(t_point **coords, char *line, int width, int height)
{
	int				z;
	static int		i;
	static int		m_size;
	t_point			*copy;

	if (!i)
	{
		i = 0;
		m_size = 0;
	}
	if (m_size <= i)
	{
		if (!(copy = (t_point*)malloc(sizeof(t_point) * (m_size += D_CRDS_S))))
			pr_error("memory allocation error");
		copy = (t_point*)ft_memcpy((void*)copy, (void*)*coords,
		i * sizeof(t_point));
		ft_memdel((void**)coords);
		*coords = copy;
	}
	z = ft_atoi(line);
	(*coords)[i].x = width;
	(*coords)[i].y = height;
	(*coords)[i].z = z;
	(*coords)[i].colour = COLOUR_POINT;
	++i;
}

char	is_correct_char(char c)
{
	if (ft_isdigit(c) || c == '-')
		return (TRUE);
	return (FALSE);
}

void	check_map_width(int width, int height)
{
	static int		old_width;

	if (height == 1)
		old_width = width;
	else if (old_width != width)
		pr_error("wrong map width");
}
