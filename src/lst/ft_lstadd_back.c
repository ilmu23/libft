/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:29:29 by ivalimak          #+#    #+#             */
/*   Updated: 2024/05/26 19:33:58 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstadd_back.c
 */

#include "lft_gc.h"
#include "lft_lst.h"

/** @brief Adds a new node to the back of a list
 *
 * Adds a new node to the list, initializing the list size
 * if the list is empty
 * @param **list Address of the head pointer to the list
 * @param *node Address of the new node
 */
void	ft_lstadd_back(const t_list **list, t_list *node)
{
	t_list	*last;
	uint8_t	ptstatus;

	if (!list || !node)
		return ;
	ptstatus = ft_pushtrap_status();
	ft_pushtrap(PTRAP_DISABLE);
	ft_lstpush(node);
	last = ft_lstlast(*list);
	if (!last)
	{
		node->size = ft_push(ft_calloc(1, sizeof(*node->size)));
		ft_pushtrap(ptstatus);
		if (!node->size)
			return ;
		*list = node;
	}
	else
	{
		ft_pushtrap(ptstatus);
		node->size = last->size;
		node->prev = last;
		last->next = node;
	}
	(*node->size)++;
}
