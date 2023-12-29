/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:37:25 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/29 14:10:52 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *str)
{
	long	out;
	int		n;

	n = 1;
	out = 0;
	while (ft_isspace(*str) != 0)
		str++;
	if (*str == '-')
		n = -n;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str) != 0)
	{
		if (out > LONG_MAX / 10 || (out == LONG_MAX / 10 && *str > '7'))
		{
			if (n < 0)
				return (0);
			return (-1);
		}
		out = out * 10 + (*str - '0');
		str++;
	}
	return (out * n);
}
