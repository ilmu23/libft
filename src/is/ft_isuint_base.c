/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isuint_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 05:49:41 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/14 06:35:35 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_isuint_base.c
 */

#include "lft_isint.h"

static inline size_t	maxlen(t_base base);

/** @brief Checks if n is a valid unsigned integer representation
 *
 * @param *n String to check
 * @param base Base to check with
 * @retval uint8_t 1 if n is valid, 0 if not
 */
uint8_t	ft_isuint_base(const char *n, t_base base)
{
	const char	*nbrarr = getnbrs(base);
	uint64_t	nbr;

	n = trimzeros(n);
	if (!n || ft_strlen(n) > maxlen(base) + (*n == '+'))
		return (0);
	nbr = ft_atou_base(n, base);
	if (nbr == 0 && !ft_strequals(n, "0"))
		return (0);
	if (*n == '+')
		n++;
	while (*n)
	{
		if (!inbase(nbrarr, *n++))
			return (0);
	}
	return (1);
}
static inline size_t	maxlen(t_base base)
{
	if (base == BINARY)
		return (64);
	if (base == OCTAL)
		return (22);
	if (base == DECIMAL)
		return (20);
	return (16);
}
