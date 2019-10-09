/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hash_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:12:15 by aashara-          #+#    #+#             */
/*   Updated: 2019/09/17 20:53:27 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libhash.h"

void	*get_hash_data(t_hash **table, char *hash_str, size_t size)
{
	size_t	index;
	size_t	key;
	t_hash	*hash;

	key = djb2_hash_function(hash_str);
	index = hash_index(key, size);
	hash = table[index];
	while (hash && key != hash->hash_key)
		hash = hash->next;
	if (hash)
		return (hash->data);
	return (NULL);
}
