/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sweep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:14:57 by ivalimak          #+#    #+#             */
/*   Updated: 2024/06/11 17:34:41 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_sweep.c
 */

#include "lft_put.h"
#include "_internal/lft_gc_internal.h"

/** @brief Frees all unmarked objects
 *
 * Goes through all allocated blocks, freeing them if they haven't
 * been marked as in use
 */
void	ft_sweep(void)
{
	static t_vm	*vm = NULL;
	t_obj		**obj;
	t_obj		*tmp;

	if (!vm)
		vm = ft_getvm();
	obj = &vm->head;
	while (*obj)
	{
		if (!(*obj)->marks)
		{
			tmp = *obj;
			*obj = tmp->next;
			vm->objcount--;
			ft_debugmsg(GCSWEEP, "Freeing unused block at %p", tmp->blk);
			ft_debugmsg(GCSWEEP, "Freeing unused obj at %p", tmp);
			gc_objmap_rm(gc_blkkey(tmp->blk));
			free((void *)tmp->blk);
			free(tmp);
		}
		else
			obj = &(*obj)->next;
	}
}
