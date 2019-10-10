/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_other.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 20:48:11 by aashara-          #+#    #+#             */
/*   Updated: 2019/10/10 19:45:59 by aashara-         ###   ########.fr       */
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
	if (!(mlx->data_addr = (int*)mlx_get_data_addr(mlx->img_ptr,
	&mlx->bits_per_pixel, &mlx->size_line, &mlx->endian)))
		pr_error("mlx_get_data_addr error");
}

void	copy_point(t_point *a, t_point b)
{
	a->x = b.x;
	a->y = b.y;
	a->z = b.z;
	a->colour = b.colour;
}

void	init_draw_line_params(t_point *delta, t_point *sign, t_point start,
t_point end)
{
	delta->x = abs(end.x - start.x);
	delta->y = abs(end.y - start.y);
	sign->x = (end.x - start.x) > 0 ? 1 : -1;
	sign->y = (end.y - start.y) > 0 ? 1 : -1;
}

void	print_options(t_map *map, t_mlx_params *mlx)
{
	char	*nb;
	char	s[100];

	print_keys(mlx);
	ft_strcpy(s, ft_strcat(ft_strcpy(s, "Scale: "), nb = ft_itoa(map->scale)));
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, WIN_WIDTH - 300, 10,
	WHITE, s);
	ft_strdel(&nb);
	if (map->proj_type == ISO)
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, WIN_WIDTH - 300, 30,
		WHITE, "Projection type - ISOMETRIC");
	else
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, WIN_WIDTH - 300, 30,
		WHITE, "Projection type - PARALLEL");
	if (map->colour == YELLOW)
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, WIN_WIDTH - 300, 50,
		WHITE, "Colour - YELLOW");
	else if (map->colour == RED)
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, WIN_WIDTH - 300, 50,
		WHITE, "Colour - RED");
	else
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, WIN_WIDTH - 300, 50,
		WHITE, "Colour - STANDART");
}

void	print_keys(t_mlx_params *mlx)
{
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 10, WHITE,
	"Key `W` - up rotation around the x axis");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 30, WHITE,
	"Key `S` - down rotation around the x axis");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 50, WHITE,
	"Key `A` - left rotation around the y axis");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 70, WHITE,
	"Key `D` - right rotation around the y axis");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 90, WHITE,
	"Key `I` - change projection to isometric");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 110, WHITE,
	"Key `P` - change projection to parallel");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 130, WHITE,
	"Key `+` - increase map");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 150, WHITE,
	"Key `-` - decrease map");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 150, WHITE,
	"Key `-` - decrease map");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 170, WHITE,
	"Key `R` - set red colour");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 190, WHITE,
	"Key `Y` - set yellow colour");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 210, WHITE,
	"Key `T` - set standart colour");
}
