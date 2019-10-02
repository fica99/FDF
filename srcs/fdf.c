/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 21:55:47 by lbellona          #+#    #+#             */
/*   Updated: 2019/10/01 21:57:49 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				pr_error(char *err_msg)
{
	perror(err_msg);
	exit(EXIT_FAILURE);
}

void				check_map_width(t_map *map)
{
	static int		old_width;

	if (map->height == 1)
		old_width = map->width;
	else if (old_width != map->width)
		pr_error("wrong map width");
}

void				read_map(int fd, t_fdf *fdf)
{
	char			*line;
	t_3d_coords		*coords_lst;

	fdf->map.avg_z = 0;
	coords_lst = NULL;
	fdf->map.height = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (*line == 0)
			pr_error("wrong line from file");
		get_3d_coords(line, &coords_lst, fdf);
		ft_strdel(&line);
		check_map_width(&fdf->map);
	}
	if (!(fdf->map.coords = (t_point*)malloc(sizeof(t_point) * fdf->map.height
															* fdf->map.width))
			|| !(fdf->map.inp_coords = (t_point*)malloc(sizeof(t_point) *
											fdf->map.height * fdf->map.width)))
		pr_error("memory allocation error");
	put_coords_2_arr(coords_lst, fdf);
	clear_coords_lst(&coords_lst);
}

int					main(int argc, char **argv)
{
	int				fd;
	t_fdf			fdf;

	if (argc != 2)
		ft_putendl("Usage : ./fdf <filename>");
	else
	{
		if ((fd = open(argv[1], O_RDONLY)) < 0)
			pr_error("");
		read_map(fd, &fdf);
		//draw_landscape(&fdf);
		if ((close(fd)) < 0)
			pr_error("");
	}
	return (EXIT_SUCCESS);
}
