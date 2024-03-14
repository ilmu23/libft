/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 05:02:40 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/14 06:32:41 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_isint_base.c
 */

#include "lft_isint.h"

static inline size_t	maxlen(t_base base);

/** @brief Checks if n is a valid integer representation
 *
 * @param *n String to check
 * @param base Base to check with
 * @retval uint8_t 1 if n is valid, 0 if not
 */
uint8_t	ft_isint_base(const char *n, t_base base)
{
	const char	*nbrarr = getnbrs(base);
	int64_t		nbr;

	n = trimzeros(n);
	if (!n || ft_strlen(n) > maxlen(base) + (*n == '+' || *n == '-'))
		return (0);
	nbr = ft_atoi_base(n, base);
	if ((nbr == -1 && !ft_strequals(n, "-1"))
		|| (nbr == 0 && !ft_strequals(n, "0")))
		return (0);
	if (*n == '+' || *n == '-')
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
		return (63);
	if (base == OCTAL)
		return (21);
	if (base == DECIMAL)
		return (19);
	return (16);
}
