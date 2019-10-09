/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_fifo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 17:35:07 by olegmulko         #+#    #+#             */
/*   Updated: 2019/09/15 21:47:11 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfifo.h"

void	*ft_get_fifo(t_fifo **fifo)
{
	void	*data;
	t_fifo	*delfifo;

	if (!fifo || !*fifo)
		return (NULL);
	data = (*fifo)->data;
	delfifo = *fifo;
	*fifo = (*fifo)->next;
	ft_del_fifo(&delfifo);
	return (data);
}
