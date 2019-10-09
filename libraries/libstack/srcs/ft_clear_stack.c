/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 21:34:23 by olegmulko         #+#    #+#             */
/*   Updated: 2019/09/15 21:37:42 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstack.h"

void	ft_clear_stack(t_stack **stack)
{
	t_stack	*cur_stack;
	t_stack	*next_stack;

	if (!stack || !*stack)
		return ;
	next_stack = *stack;
	while (next_stack)
	{
		cur_stack = next_stack;
		next_stack = next_stack->next;
		ft_del_stack(&cur_stack);
	}
	stack = NULL;
}
