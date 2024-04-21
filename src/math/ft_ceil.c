/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ceil.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 06:18:55 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/21 06:28:37 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_ceil(const double n)
{
	if (n == (double)(int64_t)n)
		return (n);
	return ((double)(int64_t)n + 1.0);
}
