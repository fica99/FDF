/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libdar.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:19:00 by aashara-          #+#    #+#             */
/*   Updated: 2019/09/22 20:19:17 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBDAR_H
# define LIBDAR_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# define CHECK(val) if (!val) return (0)
# define CHECKV(val) if (!val) return

int		ft_check_exc(char *str, char **exc);
char	**ft_dar_add(char **dest, char **src, char **exc);
size_t	ft_darlen(char **dar);
void	ft_free_dar(char **arr);
char	**ft_dardup(char **arr);
char	**ft_darnew(size_t size);
void	ft_putdar(char **arr);
void	ft_putdar_fd(char **arr, int fd);
#endif
