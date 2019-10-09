/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 18:26:24 by aashara-          #+#    #+#             */
/*   Updated: 2019/09/15 21:19:15 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

char	*ft_stradd(char *buf, char *s, size_t i)
{
	char	*str;

	if (!s)
		return (buf);
	if (i >= ft_strlen(buf))
		return (ft_strcat(buf, s));
	if (!(str = ft_strdup(buf + i)))
		return (NULL);
	*(buf + i) = '\0';
	buf = ft_strcat(ft_strcat(buf, s), str);
	ft_memdel((void**)&str);
	return (buf);
}
