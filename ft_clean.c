/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:29:27 by ivalimak          #+#    #+#             */
/*   Updated: 2024/01/01 14:44:28 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_clean.c
 */

#include "libft.h"

/** @brief Finds all unused allocations and frees them
 *
 * @param *vm Pointer to the virtual memory manager
 */
void	ft_clean(void)
{
	t_vm	*vm;

	vm = ft_getvm();
	if (DEBUG_MSG)
		ft_dprintf(DEBUGFD, "Cleaning...\n");
	ft_markall(vm);
	ft_sweep(vm);
	ft_unmarkall(vm);
	if (vm->objs > GC_START / 2)
		vm->maxobjs = vm->objs * 2;
	else
		vm->maxobjs = GC_START;
}
