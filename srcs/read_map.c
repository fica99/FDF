/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 20:27:15 by aashara-          #+#    #+#             */
/*   Updated: 2019/10/12 15:12:40 by aashara-         ###   ########.fr       */
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
		parse_coords(line, &coords, &map->width, &map->height);
		check_map_width(map->width, map->height);
		ft_strdel(&line);
	}
	if (gnl == -1)
		pr_error("Reading error");
	if (!(map->inp_coords = coords))
		pr_error("File error");
	if (!(map->coords = (t_point*)malloc(sizeof(t_point) *
	map->height * map->width)))
		pr_error("Malloc error");
}

void	parse_coords(char *line, t_point **coords, int *width, int *height)
{
	int		i;

	*width = 0;
	i = 0;
	while (line[i])
	{
		if (ft_isspace(line[i]))
		{
			++i;
			continue ;
		}
		add_coords_2_arr(coords, line + i, *width, *height);
		(*coords)[*width * (*height)].colour = parse_colour(line, &i);
		++(*width);
	}
	++(*height);
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
		return (colour);
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

void	add_coords_2_arr(t_point **coords, char *line, int width, int height)
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
	(*coords)[i].x = width;
	(*coords)[i].y = height;
	(*coords)[i].z = ft_atoi(line);
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
