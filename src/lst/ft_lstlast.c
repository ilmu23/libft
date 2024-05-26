/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:17:50 by ivalimak          #+#    #+#             */
/*   Updated: 2024/05/26 19:37:48 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstlast.c
 */

#include "lft_lst.h"

/** @brief Returns the address of the last node of the list
 *
 * @param *list Address of a node in the list
 * @retval t_list* Address of the last node in the list,
 * or NULL if list is NULL
 */
t_list	*ft_lstlast(const t_list *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return ((t_list *)list);
}
