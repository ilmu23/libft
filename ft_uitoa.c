/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:22:58 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/30 16:20:43 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_uitoa.c
 */

#include "libft.h"

/** @brief Converts n into a string
 *
 * @param n Unsigned integer to be converted into
 * an ascii representation of its value
 * @retval char * Pointer to the allocated string
 * or NULL if the allocation failed
 */
char	*ft_uitoa(unsigned int n)
{
	char	*out;
	size_t	i;

	i = ft_uintlen(n);
	if (DEBUG_MSG)
	{
		out = malloc((i-- + 1) * sizeof(char));
		out[i + 1] = '\0';
	}
	else
		out = ft_calloc(i-- + 1, sizeof(char));
	if (!out)
		return (NULL);
	while (n > 9)
	{
		out[i--] = n % 10 + '0';
		n /= 10;
	}
	out[i] = n + '0';
	return (out);
}
