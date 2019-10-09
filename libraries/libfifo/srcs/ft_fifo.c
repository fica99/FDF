/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fifo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 11:37:37 by olegmulko         #+#    #+#             */
/*   Updated: 2019/09/15 21:55:01 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfifo.h"

static t_list	*ft_get_fifolist(const size_t id, t_list **list)
{
	t_list				*plist;

	plist = *list;
	while (plist)
	{
		if (plist->content_size == id)
			return (plist);
		plist = plist->next;
	}
	if (!(plist = ft_lstnew(NULL, 0)))
		return (NULL);
	plist->content = NULL;
	plist->content_size = id;
	ft_lstadd(list, plist);
	return (plist);
}

static void		ft_del_list(t_list **list, size_t id)
{
	t_list	*parent_list;
	t_list	*plist;
	t_list	*del_list;

	if (!list || !*list)
		return ;
	plist = *list;
	while (plist)
	{
		if (plist->content_size == id)
		{
			*list = plist->next;
			free(plist);
			return ;
		}
		if ((plist->next)->content_size == id)
		{
			parent_list = plist;
			del_list = plist->next;
			parent_list->next = del_list->next;
			free(del_list);
			return ;
		}
		plist = plist->next;
	}
}

void			*ft_fifo(size_t fifo_id, char *method, void *data)
{
	static t_list	*fifo_list;
	t_list			*sel_list;
	void			*res;

	sel_list = ft_get_fifolist(fifo_id, &fifo_list);
	if (ft_strcmp(method, "add") == 0)
		sel_list->content = (void *)ft_add_fifo((t_fifo *)sel_list->content,
		data);
	else if (ft_strcmp(method, "get") == 0)
	{
		res = ft_get_fifo((t_fifo **)&sel_list->content);
		if (!res)
			ft_del_list(&fifo_list, fifo_id);
		return (res);
	}
	else if (ft_strcmp(method, "clear") == 0)
	{
		ft_clear_fifo((t_fifo **)&sel_list->content);
		ft_del_list(&fifo_list, fifo_id);
	}
	else if (ft_strcmp(method, "size") == 0)
		return ((void *)(((t_fifo *)(sel_list->content))->fifo_size));
	return (NULL);
}
