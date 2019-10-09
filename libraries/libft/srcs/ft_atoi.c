/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 19:39:28 by aashara-          #+#    #+#             */
/*   Updated: 2019/09/25 17:56:48 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	res;
	size_t				s_len;

	if (!str)
		return (0);
	sign = 1;
	res = 0;
	while (*str == '\t' || *str == '\v' || *str == '\f' || *str == '\r'
			|| *str == '\n' || *str == ' ')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	s_len = 0;
	while (*str >= 48 && *str <= 57)
	{
		res *= 10;
		res += *str - '0';
		str++;
		if (res > LLONG_MAX || (res < ULLONG_MAX && ++s_len >= 20))
			return (sign == 1 ? -1 : 0);
	}
	return (sign * (int)res);
}
