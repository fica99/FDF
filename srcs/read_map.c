/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 20:27:15 by aashara-          #+#    #+#             */
/*   Updated: 2019/10/12 18:04:12 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	read_map(int fd, t_map *map)
{
	char	*line;
	t_point	*coords;
	int		gnl;

	map->height = 0;
	coords = NULL;
	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		parse_coords(line, &coords, map);
		check_map_width(map->width, map->height);
		ft_strdel(&line);
	}
	if (gnl == -1)
		pr_error("Reading error");
	if (!(map->inp_coords = transform_coords(coords, map->height,
	map->width)))
		pr_error("File error");
}

void	parse_coords(char *line, t_point **coords, t_map *map)
{
	int		i;

	map->width = 0;
	i = 0;
	while (line[i])
	{
		if (ft_isspace(line[i]))
		{
			++i;
			continue ;
		}
		add_coords_2_arr(coords, line, &i, map);
		++map->width;
	}
	++map->height;
}

int		parse_colour(char *str, int *i)
{
	int		colour;
	char	*s;
	char	*base;

	base = "0123456789ABCDEF0123456789abcdef";
	colour = 0;
	if (str[*i] == '-')
		++(*i);
	while (ft_isdigit(str[*i]))
		++(*i);
	if (ft_isspace(str[*i]) || !str[*i])
		return (DEFAULT);
	if (!ft_strncmp(str + (*i), ",0x", 3) ||
	!ft_strncmp(str + (*i), ",0X", 3))
		(*i) += 2;
	else
		pr_error("Map error");
	while ((s = ft_strchr(base, str[++(*i)])) && *s)
		colour = colour * 16 + ((s - base) % 16);
	if (!(ft_isspace(str[*i]) || !str[*i]))
		pr_error("Map error");
	return (colour);
}

void	add_coords_2_arr(t_point **coords, char *line, int *index, t_map *map)
{
	static int		i;
	static int		malloc_size;
	t_point			*copy;

	if (malloc_size <= i)
	{
		if (!(copy = (t_point*)malloc(sizeof(t_point) *
		(malloc_size += DEF_COORDS_SIZE))))
			pr_error("Malloc error");
		copy = (t_point*)ft_memcpy((void*)copy, (void*)*coords,
		i * sizeof(t_point));
		ft_memdel((void**)coords);
		*coords = copy;
	}
	(*coords)[i].x = map->width;
	(*coords)[i].y = map->height;
	(*coords)[i].z = ft_atoi(line + (*index));
	(*coords)[i].colour = parse_colour(line, index);
	++i;
}

void	check_map_width(int width, int height)
{
	static int		old_width;

	if (height == 1)
		old_width = width;
	else if (old_width != width)
		pr_error("Wrong width");
}
