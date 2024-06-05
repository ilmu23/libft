/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:39:17 by ivalimak          #+#    #+#             */
/*   Updated: 2024/06/06 00:46:26 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_pop.c
 */

#include "lft_put.h"
#include "_internal/lft_gc_internal.h"

/** @brief Pops all blocks from the vm stack
 */
void	ft_popall(void)
{
	static t_vm	*vm = NULL;

	if (!vm)
		vm = ft_getvm();
	ft_popn(vm->objcount);
}

/** @brief Pops blks amount of blocks from the vm stack
 *
 * @param blks Amount of blocks to pop
 */
void	ft_popn(size_t blks)
{
	static t_vm	*vm = NULL;
	t_obj		*obj;

	if (!vm)
		vm = ft_getvm();
	obj = vm->head;
	while (obj && blks--)
	{
		obj->marks = 0;
		obj->traps = 0;
		obj = obj->next;
	}
}

/** @brief Pops the block blk from the stack, if present
 *
 * @param *blk Address of block to be popped
 */
void	ft_popblk(const void *blk)
{
	static t_vm	*vm = NULL;

	if (!blk)
		return ;
	if (!vm)
		vm = ft_getvm();
	ft_unmark(blk);
	ft_debugmsg(GCPOP, "Popping block %p", blk);
}

/** @brief Pops all the blocks given from the stack
 *
 * @param blks Amount of blocks to pop
 * @param ... Blocks to pop
 */
void	ft_popblks(size_t blks, ...)
{
	va_list	args;

	va_start(args, blks);
	while (blks)
	{
		ft_popblk(va_arg(args, void *));
		blks--;
	}
	va_end(args);
}
