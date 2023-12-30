/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinteger.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:32:59 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/30 12:08:04 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_isinteger.c
 */

#include "libft.h"

/** @brief Checks if the string n is an integer in text form
 *
 * @param *n String to check
 * @retval int 1 if *s is an integer, 0 if not
 */
int	ft_isinteger(char *n)
{
	size_t	i;
	long	nbr;

	i = 0;
	while (n[i])
	{
		if (ft_isdigit(n[i]) == 0 && (n[i] != '-' || n[i] != '+'))
			return (0);
		i++;
	}
	nbr = ft_atol(n);
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (0);
	return (1);
}
