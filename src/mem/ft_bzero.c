/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:52:55 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/13 12:49:47 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_bzero.c
 */

#include "lft_mem.h"

/** @brief Sets n bytes to 0 starting at s
 *
 * @param s Pointer to start setting at
 * @param n Amount of bytes to set
 */
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
