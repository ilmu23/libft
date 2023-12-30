/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:06:35 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/30 12:13:56 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_itoa.c
 */

#include "libft.h"

/** @brief Converts n into a string
 *
 * @param n Integer to be converted into a character representation of its value
 * @retval char * Pointer to the allocated text representation of n, or NULL if
 * allocation failed
 */
char	*ft_itoa(int n)
{
	int		neg;
	char	*out;
	size_t	i;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	i = ft_intlen(n);
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
