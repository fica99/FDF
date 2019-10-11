/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 21:17:44 by aashara-          #+#    #+#             */
/*   Updated: 2019/10/11 16:51:19 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_handler(int key, t_fdf *fdf)
{
	key == 53 ? exit(EXIT_SUCCESS) : 0;
	key == 13 ? fdf->map->angle_x += PI_32 : 0;
	key == 1 ? fdf->map->angle_x -= PI_32 : 0;
	key == 0 ? fdf->map->angle_y -= PI_32 : 0;
	key == 2 ? fdf->map->angle_y += PI_32 : 0;
	key == 16 ? fdf->map->colour = YELLOW : 0;
	key == 15 ? fdf->map->colour = RED : 0;
	key == 17 ? fdf->map->colour = STANDART : 0;
	if (key == 24)
		if (fdf->map->scale < INT_MAX)
			++fdf->map->scale;
	if (key == 27)
		if (fdf->map->scale > 1)
			--fdf->map->scale;
	if (key == 34 || key == 35)
	{
		fdf->map->proj_type = PARALLEL;
		if (key == 34)
			fdf->map->proj_type = ISO;
		unset_angl(&fdf->map->angle_x, &fdf->map->angle_y);
	}
	ft_bzero(fdf->mlx.data_addr, WIN_WIDTH * WIN_HEIGHT *
	(fdf->mlx.bits_per_pixel / 8));
	draw(fdf->map, &fdf->mlx);
}

void	close_window(t_fdf *fdf)
{
	(void)fdf;
	exit(EXIT_SUCCESS);
}
