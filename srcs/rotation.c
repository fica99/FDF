/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 19:59:59 by aashara-          #+#    #+#             */
/*   Updated: 2019/10/09 18:52:59 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotation_x(int *y, int *z, double angle_x)
{
	int				y_copy;
	int				z_copy;

	y_copy = *y;
	z_copy = *z;
	*y = y_copy * cos(angle_x) + z_copy * sin(angle_x);
	*z = -y_copy * sin(angle_x) + z_copy * cos(angle_x);
}

void	rotation_y(int *x, int *z, double angle_y)
{
	int				x_copy;
	int				z_copy;

	x_copy = *x;
	z_copy = *z;
	*x = x_copy * cos(angle_y) + z_copy * sin(angle_y);
	*z = -x_copy * sin(angle_y) + z_copy * cos(angle_y);
}
