/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 21:54:42 by olegmulko         #+#    #+#             */
/*   Updated: 2019/09/15 21:37:56 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstack.h"

void	*ft_get_stack(t_stack **stack)
{
	void	*data;
	t_stack	*delstack;

	if (!stack || !*stack)
		return (NULL);
	data = (*stack)->data;
	delstack = *stack;
	*stack = (*stack)->next;
	ft_del_stack(&delstack);
	return (data);
}
