/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 21:17:44 by aashara-          #+#    #+#             */
/*   Updated: 2019/10/12 15:25:31 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_handler(int key, t_fdf *fdf)
{
	key == K_ESC ? exit(EXIT_SUCCESS) : 0;
	key == K_W ? fdf->map->angle_x += PI_32 : 0;
	key == K_S ? fdf->map->angle_x -= PI_32 : 0;
	key == K_A ? fdf->map->angle_y -= PI_32 : 0;
	key == K_D ? fdf->map->angle_y += PI_32 : 0;
	key == K_Y ? fdf->map->colour = YELLOW : 0;
	key == K_R ? fdf->map->colour = RED : 0;
	key == K_T ? fdf->map->colour = STANDART : 0;
	if (key == K_PLUS)
		if (fdf->map->scale < INT_MAX)
			++fdf->map->scale;
	if (key == K_MINUS)
		if (fdf->map->scale > 1)
			--fdf->map->scale;
	if (key == K_I || key == K_P)
	{
		fdf->map->proj_type = PARALLEL;
		if (key == K_I)
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
