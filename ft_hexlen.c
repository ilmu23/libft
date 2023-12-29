/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:54:19 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/29 15:55:32 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_hexlen(unsigned long n)
{
	size_t	digits;

	digits = 1;
	while (n > 15)
	{
		n /= 16;
		digits++;
	}
	return (digits);
}
