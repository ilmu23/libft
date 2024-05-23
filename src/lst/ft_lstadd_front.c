/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:19:16 by ivalimak          #+#    #+#             */
/*   Updated: 2024/05/23 21:41:19 by ivalimak         ###   ########.fr       */
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
void	ft_lstadd_front(t_list **list, t_list *node)
{
	uint8_t	ptstatus;

	if (!list || !node)
		return ;
	ptstatus = ft_pushtrap_status();
	ft_pushtrap(PTRAP_DISABLE);
	ft_lstpush(node);
	if (!*list)
	{
		node->size = ft_push(ft_calloc(1, sizeof(*node->size)));
		ft_pushtrap(ptstatus);
		if (!node->size)
			return ;
	}
	else
	{
		ft_pushtrap(ptstatus);
		node->size = (*list)->size;
		(*list)->prev = node;
		node->next = *list;
	}
	*list = node;
	(*node->size)++;
}
