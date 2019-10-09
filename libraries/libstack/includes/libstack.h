/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libstack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 21:26:30 by olegmulko         #+#    #+#             */
/*   Updated: 2019/09/15 21:37:33 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSTACK_H
# define LIBSTACK_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct		s_stack
{
	size_t			id;
	void			*data;
	size_t			*stack_size;
	struct s_stack	*next;
}					t_stack;

t_stack				*ft_newstack(size_t id, void *data, size_t **stack_size);
void				ft_del_stack(t_stack **stack);
void				ft_clear_stack(t_stack **stack);
t_stack				*ft_add_stack(t_stack *stack, void *data);
void				*ft_get_stack(t_stack **stack);
void				*ft_stack(size_t stack_id, char *method, void *data);

#endif
