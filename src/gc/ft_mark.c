/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mark.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:08:26 by ivalimak          #+#    #+#             */
/*   Updated: 2024/06/11 17:33:05 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_mark.c
 */

#include "_internal/lft_gc_internal.h"

/** @brief Removes a mark from blk
 *
 * @param *blk Pointer to the block to set an not in use
 */
void	ft_unmark(const void *blk)
{
	static t_vm	*vm = NULL;
	t_obj		*obj;

	if (!vm)
		vm = ft_getvm();
	obj = gc_getobj(blk);
	if (obj && obj->marks)
	{
		obj->marks--;
		if (obj->traps)
			obj->traps--;
		if (!obj->marks && obj->blksize)
		{
			if (vm->free)
				vm->free->pfree = obj;
			obj->nfree = vm->free;
			vm->free = obj;
		}
	}
}

/** @brief Adds a mark to blk
 *
 * @param *blk Pointer to the block to set as in use
 */
void	ft_mark(const void *blk)
{
	static t_vm	*vm = NULL;
	t_obj		*obj;

	if (!vm)
		vm = ft_getvm();
	obj = gc_getobj(blk);
	if (obj)
	{
		obj->marks++;
		if (vm->ptrap)
			obj->traps++;
		if (obj->nfree)
		{
			obj->nfree->pfree = obj->pfree;
			obj->nfree = NULL;
		}
		if (obj->pfree)
		{
			obj->pfree->nfree = obj->nfree;
			obj->pfree = NULL;
		}
		else if (obj->marks == 1)
			vm->free = obj->nfree;
	}
}
