/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:10:05 by ivalimak          #+#    #+#             */
/*   Updated: 2024/05/26 19:38:26 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstpop
 */

#include "lft_gc.h"
#include "lft_lst.h"

/** @brief Pops the node and its content
 *
 * @param *node Address of the node
 * @retval t_list* Address of the node
 */
t_list	*ft_lstpop(const t_list *node)
{
	if (!node)
		return (NULL);
	ft_popblk(node);
	ft_popblk(node->blk);
	return ((t_list *)node);
}
