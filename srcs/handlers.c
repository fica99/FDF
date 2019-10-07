/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 21:17:44 by aashara-          #+#    #+#             */
/*   Updated: 2019/10/07 22:42:57 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_handler(int key, t_fdf *fdf)
{
	if (key == 53)
		exit(EXIT_SUCCESS);
	if (key == 24)
	{
		fdf->map->scale += 1;
		find_offset(fdf->map);
	}
	if (key == 27)
	{
		if (fdf->map->scale > 1)
			fdf->map->scale -= 1;
		find_offset(fdf->map);
	}
	ft_bzero(fdf->mlx.data_addr, WIN_WIDTH * WIN_HEIGHT * 4);
	put_img(&fdf->mlx, fdf->map, fdf->map->coords);
}

void	close_window(t_fdf *fdf)
{
	(void)fdf;
	exit(EXIT_SUCCESS);
}
