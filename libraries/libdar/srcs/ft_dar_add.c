/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dar_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:19:43 by aashara-          #+#    #+#             */
/*   Updated: 2019/09/11 17:19:45 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdar.h"

char	**ft_dar_add(char **dest, char **src, char **exc)
{
	int		i;
	int		j;
	char	**dar;
	int		len;

	if (!src && !*src)
		return (NULL);
	len = ft_darlen(dest);
	len += ft_darlen(src);
	CHECK((dar = (char **)malloc(sizeof(char *) * (len + 1))));
	i = (dest) ? -1 : 0;
	if (dest)
		while (dest[++i])
			dar[i] = ft_strdup(dest[i]);
	j = -1;
	while (src[++j])
		if (!ft_check_exc(src[j], exc))
			dar[i++] = ft_strdup(src[j]);
	dar[i] = NULL;
	return (dar);
}
