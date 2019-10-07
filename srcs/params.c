/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:38:18 by aashara-          #+#    #+#             */
/*   Updated: 2019/10/07 23:06:44 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scale_map(int width, int height, t_point *scale)
{
	int				sc;

	if ((sc = fmax(WIN_WIDTH, WIN_HEIGHT) / fmax(width, height)) < 1)
		sc = 1;
	scale->x = sc;
	scale->y = sc;
	scale->z = sc;
}
