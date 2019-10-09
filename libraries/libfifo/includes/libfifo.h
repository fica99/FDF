/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfifo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 11:33:32 by olegmulko         #+#    #+#             */
/*   Updated: 2019/09/15 21:45:00 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFIFO_H
# define LIBFIFO_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct		s_fifo
{
	size_t			id;
	void			*data;
	size_t			*fifo_size;
	struct s_fifo	*next;
	struct s_fifo	**last;

}					t_fifo;

t_fifo				*ft_newfifo(size_t id, void *data, size_t **fifo_size);
void				ft_del_fifo(t_fifo **fifo);
void				ft_clear_fifo(t_fifo **fifo);
t_fifo				*ft_add_fifo(t_fifo *fifo, void *data);
void				*ft_get_fifo(t_fifo **fifo);
void				*ft_fifo(size_t fifo_id, char *method, void *data);

#endif
