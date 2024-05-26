/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:19:16 by ivalimak          #+#    #+#             */
/*   Updated: 2024/05/26 19:35:42 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstadd_front.c
 */

#include "lft_gc.h"
#include "lft_lst.h"

/** @brief Adds a new node to the front of a list
 *
 * Adds a new node to the list, initializing the list size
 * if the list is empty
 * @param **list Address of the head pointer to the list
 * @param *node Address of the new node
 */
void	ft_lstadd_front(const t_list **list, t_list *node)
{
	t_list	*first;
	uint8_t	ptstatus;

	if (!list || !node)
		return ;
	ptstatus = ft_pushtrap_status();
	ft_pushtrap(PTRAP_DISABLE);
	ft_lstpush(node);
	first = ft_lstfirst(*list);
	if (!first)
	{
		node->size = ft_push(ft_calloc(1, sizeof(*node->size)));
		ft_pushtrap(ptstatus);
		if (!node->size)
			return ;
	}
	else
	{
		ft_pushtrap(ptstatus);
		node->size = first->size;
		first->prev = node;
		node->next = first;
	}
	*list = node;
	(*node->size)++;
}
