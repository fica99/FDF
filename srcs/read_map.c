/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 20:27:15 by aashara-          #+#    #+#             */
/*   Updated: 2019/10/10 22:29:40 by aashara-         ###   ########.fr       */
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
		check_map_width(map->width, ++map->height);
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

void	parse_coords(char *line, t_point **coords, t_map *map)
{
	int		i;
	char	**str;

	i = -1;
	map->width = 0;
	if (!(str = ft_strsplit(line, ' ')))
		pr_error("Malloc error");
	while (str[++i])
	{
		add_coords_2_arr(coords, str[i], map->width, map->height);
		(*coords)[map->width * map->height].colour = parse_colour(str[i]);
		ft_memdel((void**)&str[i]);
		++map->width;
	}
	ft_memdel((void**)str);
}

int		parse_colour(char *str)
{
	int		i;
	int		colour;
	char	*s;
	char	*base;

	i = 0;
	base = "0123456789ABCDEF0123456789abcdef";
	colour = 0;
	while (str[i] && ft_isdigit(str[i]))
		++i;
	if (str[i] && str[i] == ',' && str[i + 1] == '0' &&
		(str[i + 2] == 'x' || str[i + 2] == 'X'))
	{
		i += 2;
		while (str[++i])
			if ((s = ft_strchr(base, str[i])))
				colour = colour * 16 + ((s - base) % 16);
			else
				return (colour);
	}
	return (colour);
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
			pr_error("Malloc error");
		copy = (t_point*)ft_memcpy((void*)copy, (void*)*coords,
		i * sizeof(t_point));
		ft_memdel((void**)coords);
		*coords = copy;
	}
	z = ft_atoi(line);
	(*coords)[i].x = width;
	(*coords)[i].y = height;
	(*coords)[i].z = z;
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
