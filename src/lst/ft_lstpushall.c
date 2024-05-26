/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:52:29 by ivalimak          #+#    #+#             */
/*   Updated: 2024/05/26 19:38:37 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstpushall.c
 */

#include "lft_lst.h"

/** @brief Pushes all nodes in the list
 *
 * @param *list Address of the first node of the list
 */
void	ft_lstpushall(const t_list *list)
{
	while (list)
	{
		ft_lstpop(list);
		list = list->next;
	}
}
