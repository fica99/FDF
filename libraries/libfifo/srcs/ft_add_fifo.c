/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_fifo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 12:52:24 by olegmulko         #+#    #+#             */
/*   Updated: 2019/09/15 21:44:05 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfifo.h"

static t_fifo	*ft_newfifolist(t_fifo *fifo, t_fifo *newfifo)
{
	t_fifo	**last;

	if (!fifo)
	{
		if (!(last = (t_fifo **)malloc(sizeof(t_fifo *))))
			return (NULL);
		*last = newfifo;
		newfifo->last = last;
		return (newfifo);
	}
	else
	{
		last = fifo->last;
		newfifo->last = last;
		(*last)->next = newfifo;
		*last = newfifo;
		return (fifo);
	}
}

static size_t	*ft_size(t_fifo *fifo)
{
	size_t	*fifo_size;

	if (!fifo)
	{
		if (!(fifo_size = (size_t *)malloc(sizeof(size_t))))
			return (NULL);
		*fifo_size = 1;
	}
	else
	{
		fifo_size = fifo->fifo_size;
		(*fifo_size)++;
	}
	return (fifo_size);
}

t_fifo			*ft_add_fifo(t_fifo *fifo, void *data)
{
	t_fifo	*newfifo;
	size_t	*fifo_size;

	if (!data)
		return (fifo);
	fifo_size = ft_size(fifo);
	if (!(newfifo = ft_newfifo(*fifo_size, data, &fifo_size)))
		return (NULL);
	fifo = ft_newfifolist(fifo, newfifo);
	return (fifo);
}
