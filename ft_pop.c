/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:39:17 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/01 17:19:05 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_pop.c
 */

#include "libft.h"

/** @brief Pops all blocks from the vm stack
 */
void	ft_popall(void)
{
	ft_popn(ft_getvm()->stacksize);
}

/** @brief Pops blks amount of blocks from the vm stack
 *
 * @param blks Amount of blocks to pop
 */
void	ft_popn(size_t blks)
{
	while (blks)
	{
		ft_pop();
		blks--;
	}
}

/** @brief Pops a block from the vm stack
 *
 * @retval void * Pointer to the popped block
 */
void	*ft_pop(void)
{
	t_vm	*vm;

	vm = ft_getvm();
	if (vm->stacksize == 0)
	{
		ft_putendl_fd("GC: pop: stack underflow", 2);
		ft_exit(E_STACKUF);
	}
	if (DEBUG_MSG)
		ft_dprintf(DEBUGFD, "%s Popping block %p\n%s", GCPOP,
			vm->stack[vm->stacksize - 1], GCRESET);
	return (vm->stack[--vm->stacksize]);
}
