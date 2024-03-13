/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:41:00 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/13 12:44:33 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file
 */

#include "lft_is.h"

/** @brief Checks if is an alphabetical character
 *
 * @param c Character to check
 * @retval int 1 if c is alphabetical, 0 if not
 */
uint8_t	ft_isalpha(uint8_t c)
{
	if (ft_isupper(c) || ft_islower(c))
		return (1);
	return (0);
}
