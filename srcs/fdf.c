/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 21:55:47 by lbellona          #+#    #+#             */
/*   Updated: 2019/10/10 22:33:38 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		pr_error(char *err_msg)
{
	perror(err_msg);
	exit(EXIT_FAILURE);
}

int			main(int argc, char **argv)
{
	int		fd;
	t_map	map;
	char	*name;

	if (argc != 2)
		pr_error("Usage : ./fdf <filename>\n");
	else
	{
		if (!(name = ft_strrchr(argv[1], '/')))
			name = argv[1];
		else
			++name;
		if ((fd = open(argv[1], O_RDONLY)) < 0)
			pr_error("Open error");
		read_map(fd, &map);
		if ((close(fd)) < 0)
			pr_error("Close error");
		draw_landscape(&map, name);
		ft_memdel((void**)&map.coords);
		ft_memdel((void**)&map.inp_coords);
	}
	return (EXIT_SUCCESS);
}
