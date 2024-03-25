/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:35:34 by ivalimak          #+#    #+#             */
/*   Updated: 2024/03/24 19:32:13 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_push.c
 */

#include "lft_gc.h"
#include "lft_put.h"

/** @brief Pushes blk to the vm stack
 *
 * Pushes blk to the vm stack. If the vm stack is full
 * exits the program with ft_exit
 * @param blk Pointer to the block to be pushed to the vm stack
 * @retval void * Pointer to the block that was pushed to the vm stack
 */
void	*ft_push(void *blk)
{
	if (blk)
	{
		ft_stackadd(blk);
		ft_debugmsg(GCPUSH, "Pushing block %p", blk);
	}
	return (blk);
}

/** @brief Pushes all blocks in an array to the vm stack
 *
 * Pushes arr to the vm stack, then goes through arr pushing
 * all of its elements to the vm stack as well
 * @param addr Pointer to the pointer array to be pushed to the vm stack
 * @retval void * Pointer to the pointer array that was pushed to the vm stack
 */
void	*ft_pusharr(void *addr)
{
	void	**arr;

	ft_push(addr);
	arr = addr;
	while (arr && *arr)
		ft_push(*arr++);
	return (addr);
}

/** @brief Pushes blks blocks to the vm stack
 *
 * @param blks Amount of blocks to push to the vm stack
 * @param ... Blocks to push to the vm stack
 */
void	ft_pushn(size_t blks, ...)
{
	va_list	args;

	va_start(args, blks);
	while (blks)
	{
		ft_push(va_arg(args, void *));
		blks--;
	}
	va_end(args);
}
