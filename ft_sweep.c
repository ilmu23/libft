/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sweep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:14:57 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/30 15:56:50 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_sweep.c
 */

#include "libft.h"

/** @brief Frees all unmarked objects
 *
 * Goes through all allocated blocks, freeing them if they haven't
 * been marked as in use
 * @param *vm Pointer to the virtual memory manager
 */
void	ft_sweep(t_vm *vm)
{
	t_obj	**obj;
	t_obj	*tmp;

	obj = &vm->head;
	while (*obj)
	{
		if (!(*obj)->marked)
		{
			tmp = *obj;
			*obj = tmp->next;
			vm->objs--;
			if (DEBUG_MSG)
				ft_dprintf(DEBUGFD, "Freeing unused block at %p (%u bytes)\n",
					tmp, tmp->blksize);
			free(tmp->blk);
			free(tmp);
		}
		else
			obj = &(*obj)->next;
	}
}
