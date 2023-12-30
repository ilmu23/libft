/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 22:46:19 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/30 11:36:52 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_exit.c
 */

#include "libft.h"

/** @brief Frees all allocated memory and exits the program
 *
 * @param estat Exit status to be passed to exit() after garbage collection
 */
void	ft_exit(int estat)
{
	ft_popall();
	ft_clean(ft_getvm());
	exit(estat);
}
