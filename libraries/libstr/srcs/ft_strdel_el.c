/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel_el.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 18:24:12 by aashara-          #+#    #+#             */
/*   Updated: 2019/09/15 21:17:46 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

char		*ft_strdel_el(char *buf, size_t i)
{
	char	*str;

	if (i >= ft_strlen(buf))
		return (buf);
	str = NULL;
	if (buf + i + 1)
		if (!(str = ft_strdup(buf + i + 1)))
			return (NULL);
	*(buf + i) = '\0';
	buf = ft_strcat(buf, str);
	ft_memdel((void**)&str);
	return (buf);
}
