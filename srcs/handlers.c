/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 21:17:44 by aashara-          #+#    #+#             */
/*   Updated: 2019/11/12 18:55:23 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_handler(int key, t_fdf *fdf)
{
	key == K_ESC ? exit(EXIT_SUCCESS) : 0;
	key == K_S ? fdf->map->angle_x += PI_32 : 0;
	key == K_W ? fdf->map->angle_x -= PI_32 : 0;
	key == K_A ? fdf->map->angle_y -= PI_32 : 0;
	key == K_D ? fdf->map->angle_y += PI_32 : 0;
	key == K_E ? fdf->map->angle_z -= PI_32 : 0;
	key == K_Q ? fdf->map->angle_z += PI_32 : 0;
	if (key == K_Y || key == K_R || key == K_T)
		change_colour(fdf->map, key);
	if (key == K_PLUS)
		if (fdf->map->scale < INT_MAX)
			++fdf->map->scale;
	if (key == K_MINUS)
		if (fdf->map->scale > 1)
			--fdf->map->scale;
	if (key == K_P || key == K_I)
	{
		fdf->map->proj_type = PARALLEL;
		if (key == K_I)
			fdf->map->proj_type = ISO;
		unset_angl(&fdf->map->angle_x, &fdf->map->angle_y, &fdf->map->angle_z);
	}
	ft_bzero(fdf->mlx.data_addr, WIN_WIDTH * WIN_HEIGHT *
	(fdf->mlx.bits_per_pixel / 8));
	draw_map(&fdf->mlx, fdf->map);
}

void	change_colour(t_map *map, int key)
{
	int	i;
	int	size;
	int	prev_colour;

	prev_colour = map->colour;
	key == K_Y ? map->colour = YELLOW : 0;
	key == K_R ? map->colour = RED : 0;
	key == K_T ? map->colour = DEFAULT : 0;
	i = -1;
	size = map->width * map->height;
	while (++i < size)
		if (map->inp_coords[i].colour == prev_colour)
			map->inp_coords[i].colour = map->colour;
}

void	close_window(void)
{
	exit(EXIT_SUCCESS);
}
