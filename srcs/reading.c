/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 20:27:15 by aashara-          #+#    #+#             */
/*   Updated: 2019/10/02 23:31:50 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		read_map(int fd, t_fdf *fdf)
{
	char	*line;
	t_point	*coords;

	fdf->map.avg_z = 0;
	fdf->map.height = 0;
	fdf->map.malloc_size = 0;
	coords = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		get_3d_coords(line, &coords, fdf);
        check_map_width(&fdf->map);
		ft_strdel(&line);
	}
	if (!coords)
		pr_error("wrong line from file");
    set_map(fdf, &coords);
}

void		get_3d_coords(char *line, t_point **coords, t_fdf *fdf)
{
	int		i;
	int		delta;

	i = -1;
	fdf->map.width = 0;
	while (line[++i])
	{
        if (line[i] == ' ')
            continue ;
		if (is_correct_char(line[i]))
		{
			delta = i;
			while (is_correct_char(line[i]))
				++i;
			add_coords_2_arr(coords, line + delta, fdf);
			--i;
            ++fdf->map.width;
		}
		else
			pr_error("map error");
	}
	++fdf->map.height;
}

void    add_coords_2_arr(t_point **coords, char *line, t_fdf *fdf)
{
	int				z;
	static int		i;
	t_point			*copy;
	
	if (!i)
		i = 0;
	if (fdf->map.malloc_size <= i)
	{
		if (!(copy = (t_point*)malloc(sizeof(t_point) *
		(fdf->map.malloc_size += DEFAULT_COORDS_MALLOC))))
			pr_error("memory allocation error");
		copy = (t_point*)ft_memcpy((void*)copy, (void*)*coords, i * sizeof(t_point));
		ft_memdel((void**)coords);
		*coords = copy;
	}
	z = ft_atoi(line);
	(*coords)[i].x = fdf->map.width;
	(*coords)[i].y = fdf->map.height;
	(*coords)[i].z = z;
	fdf->map.avg_z += z;
	++i;
}

void        set_map(t_fdf *fdf, t_point **coords)
{
    int	i;
    int size;
    
    fdf->map.min.x = INT_MAX;
	fdf->map.max.x = INT_MIN;
	fdf->map.min.y = INT_MAX;
	fdf->map.max.y = INT_MIN;
    size = fdf->map.height * fdf->map.width;
	fdf->map.avg_z /= size;
	i = -1;
    while (++i < size)
    {
        find_min_max((*coords)[i].x, (*coords)[i].y, &fdf->map);
		(*coords)[i].z -= fdf->map.avg_z;
    } 

	fdf->map.inp_coords = *coords;
	if (!(fdf->map.coords = (t_point*)malloc(sizeof(t_point) * size)))
		pr_error("memory allocation error");
}