/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_other.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 20:48:11 by aashara-          #+#    #+#             */
/*   Updated: 2019/10/11 17:40:15 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_win_params(t_mlx_params *mlx, char *name)
{
	if (!(mlx->mlx_ptr = mlx_init()))
		pr_error("mlx_init error");
	if (!(mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
	name)))
		pr_error("mlx_new_window error");
	if (!(mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT)))
		pr_error("mlx_new_image error");
	if (!(mlx->data_addr = (char*)mlx_get_data_addr(mlx->img_ptr,
	&mlx->bits_per_pixel, &mlx->size_line, &mlx->endian)))
		pr_error("mlx_get_data_addr error");
}

void	print_options(t_map *map, t_mlx_params *mlx)
{
	char	*nb;
	char	s[100];

	print_keys(mlx);
	ft_strcpy(s, ft_strcat(ft_strcpy(s, "Scale: "), nb = ft_itoa(map->scale)));
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, WIN_WIDTH - 300, 10,
	STANDART, s);
	ft_strdel(&nb);
	if (map->proj_type == ISO)
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, WIN_WIDTH - 300, 30,
		STANDART, "Projection type - ISOMETRIC");
	else
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, WIN_WIDTH - 300, 30,
		STANDART, "Projection type - PARALLEL");
	if (map->colour == YELLOW)
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, WIN_WIDTH - 300, 50,
		STANDART, "Colour - YELLOW");
	else if (map->colour == RED)
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, WIN_WIDTH - 300, 50,
		STANDART, "Colour - RED");
	else
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, WIN_WIDTH - 300, 50,
		STANDART, "Colour - STANDART");
}

void	print_keys(t_mlx_params *mlx)
{
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 10, STANDART,
	"Key `W` - up rotation around the x axis");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 30, STANDART,
	"Key `S` - down rotation around the x axis");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 50, STANDART,
	"Key `A` - left rotation around the y axis");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 70, STANDART,
	"Key `D` - right rotation around the y axis");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 90, STANDART,
	"Key `I` - change projection to isometric");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 110, STANDART,
	"Key `P` - change projection to parallel");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 130, STANDART,
	"Key `+` - increase map");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 150, STANDART,
	"Key `-` - decrease map");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 150, STANDART,
	"Key `-` - decrease map");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 170, STANDART,
	"Key `R` - set red colour");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 190, STANDART,
	"Key `Y` - set yellow colour");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 210, STANDART,
	"Key `T` - set standart colour");
}
