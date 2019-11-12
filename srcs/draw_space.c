/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 22:15:29 by aashara-          #+#    #+#             */
/*   Updated: 2019/11/12 18:52:28 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_space(t_map *map, char *name)
{
	t_fdf			fdf;
	t_mlx_params	mlx;

	init_start_params(&mlx, map, name);
	draw_map(&mlx, map);
	fdf.mlx = mlx;
	fdf.map = map;
	mlx_hook(mlx.win_ptr, 2, 0, (void*)&key_handler, &fdf);
	mlx_hook(mlx.win_ptr, 17, 0, (void*)&close_window, NULL);
	mlx_loop(mlx.mlx_ptr);
}

void		draw_map(t_mlx_params *mlx, t_map *map)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x != map->width - 1)
				draw_line(mlx, calc_coord(x, y, map),
				calc_coord(x + 1, y, map));
			if (y != map->height - 1)
				draw_line(mlx, calc_coord(x, y, map),
				calc_coord(x, y + 1, map));
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr,
	0, 0);
	print_options(map, mlx);
}

void		print_options(t_map *map, t_mlx_params *mlx)
{
	char	*nb;
	char	s[100];

	print_keys(mlx);
	ft_strcpy(s, ft_strcat(ft_strcpy(s, "Scale: "), nb = ft_itoa(map->scale)));
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, WIN_WIDTH - 300, 10,
	DEFAULT, s);
	ft_strdel(&nb);
	if (map->proj_type == ISO)
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, WIN_WIDTH - 300, 30,
		DEFAULT, "Projection type - ISOMETRIC");
	else
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, WIN_WIDTH - 300, 30,
		DEFAULT, "Projection type - PARALLEL");
	if (map->colour == YELLOW)
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, WIN_WIDTH - 300, 50,
		DEFAULT, "Colour - YELLOW");
	else if (map->colour == RED)
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, WIN_WIDTH - 300, 50,
		DEFAULT, "Colour - RED");
	else
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, WIN_WIDTH - 300, 50,
		DEFAULT, "Colour - DEFAULT");
}

void		print_keys(t_mlx_params *mlx)
{
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 10, DEFAULT,
	"Key `W` - up rotation around the x axis");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 30, DEFAULT,
	"Key `S` - down rotation around the x axis");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 50, DEFAULT,
	"Key `A` - left rotation around the y axis");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 70, DEFAULT,
	"Key `D` - right rotation around the y axis");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 90, DEFAULT,
	"Key `Q` - left rotation around the z axis");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 110, DEFAULT,
	"Key `E` - right rotation around the z axis");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 130, DEFAULT,
	"Key `I` - change projection to isometric");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 150, DEFAULT,
	"Key `P` - change projection to parallel");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 170, DEFAULT,
	"Key `+` - increase map");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 190, DEFAULT,
	"Key `-` - decrease map");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 210, DEFAULT,
	"Key `-` - decrease map");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 230, DEFAULT,
	"Key `R` - set red colour");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 250, DEFAULT,
	"Key `Y` - set yellow colour");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 270, DEFAULT,
	"Key `T` - set default colour");
}
