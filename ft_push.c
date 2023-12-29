/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:35:34 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/30 00:14:20 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_push.c
 */

#include "libft.h"

/** @brief Pushes blk to the vm stack
 *
 * Pushes blk to the vm stack. If the vm stack is full
 * exits the program with ft_exit
 * @param blk Pointer to the block to be pushed to the vm stack
 * @retval void * Pointer to the block that was pushed to the vm stack
 */
void	*ft_push(void *blk)
{
	t_vm	*vm;

	vm = ft_getvm();
	if (vm->stacksize >= STACK_MAX)
	{
		ft_putendl_fd("vm: ft_push(): stack overflow", 2);
		ft_exit(E_STACKOF);
	}
	if (blk)
		vm->stack[vm->stacksize++] = blk;
	return (blk);
}

/** @brief Pushes all blocks in an array to the vm stack
 *
 * Pushes arr to the vm stack, then goes through arr pushing
 * all of its elements to the vm stack as well
 * @param arr Pointer to the pointer array to be pushed to the vm stack
 * @retval void ** Pointer to the pointer array that was pushed to the vm stack
 */
void	**ft_pusharr(void **arr)
{
	size_t	i;

	i = 0;
	ft_push(arr);
	while (arr && arr[i])
		ft_push(arr[i++]);
	return (arr);
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
