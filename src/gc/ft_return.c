/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 07:43:06 by ivalimak          #+#    #+#             */
/*   Updated: 2024/06/07 16:19:40 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_return.c
 */

#include "_internal/lft_gc_internal.h"

/** @brief Frees all memory before returning
 *
 * @param rval Return value
 * @retval int rval
 */
int	ft_return(int rval)
{
	ft_popall();
	ft_clean();
	free(ft_getvm()->objmap.objs);
	return (rval);
}
