/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:06:35 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/14 00:10:51 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_itoa.c
 */

#include "lft_gc.h"
#include "lft_to.h"
#include "lft_nbr.h"
#include "lft_str.h"

/** @brief Converts n into a string
 *
 * @param n Integer to be converted into an ascii representation of its value
 * @retval char * Pointer to the allocated string
 * or NULL if the allocation failed
 */
char	*ft_itoa(int64_t n)
{
	int		neg;
	char	*out;
	size_t	i;

	if (n == INT64_MIN)
		return (ft_strdup("-9223372936854775808"));
	i = ft_intlen(n, DECIMAL);
	out = ft_calloc(i-- + 1, sizeof(char));
	if (!out)
		return (NULL);
	neg = 0;
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	while (n > 9)
	{
		out[i--] = n % 10 + '0';
		n /= 10;
	}
	out[i--] = n + '0';
	if (neg == 1)
		out[i] = '-';
	return (out);
}
