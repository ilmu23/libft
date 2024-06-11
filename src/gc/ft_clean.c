/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:29:27 by ivalimak          #+#    #+#             */
/*   Updated: 2024/06/07 15:47:14 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_clean.c
 */

#include "lft_put.h"
#include "_internal/lft_gc_internal.h"

/** @brief Finds all unused allocations and frees them
 *
 * @param *vm Pointer to the virtual memory manager
 */
void	ft_clean(void)
{
	static t_vm	*vm = NULL;

	if (!vm)
		vm = ft_getvm();
	if (!vm->head)
	{
		ft_debugmsg(GCCLEAN, "Nothing allocated");
		return ;
	}
	ft_debugmsg(GCCLEAN, "Cleaning...");
	ft_sweep();
	if (vm->objcount > _GC_START / 2)
		vm->maxobjs = vm->objcount * 2;
	else
		vm->maxobjs = _GC_START;
	ft_debugmsg(GCCLEAN, "Done! Current objs: %u, next clean at %u objs",
		vm->objcount, vm->maxobjs);
}
