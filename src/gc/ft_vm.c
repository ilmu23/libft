/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:35:52 by ivalimak          #+#    #+#             */
/*   Updated: 2024/06/07 15:37:55 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_vm.c
 */

#include "lft_mem.h"
#include "lft_put.h"
#include "_internal/lft_gc_internal.h"
#include "_internal/lft_hmap_internal.h"

/** @brief Initializes and returns a pointer to the virtual memory manager
 *
 * When called for the first time, initializes the virtual memory manager with
 * the defaults.
 * @retval t_vm * Pointer to the virtual memory manager
 */
t_vm	*ft_getvm(void)
{
	static t_vm		vm;
	static uint8_t	init = 0;

	if (!init)
	{
		vm.objmap.bsize = _GC_MAPSIZE;
		vm.objmap.size = getnextprime(_GC_MAPSIZE);
		vm.objmap.objs = malloc(vm.objmap.size * sizeof(t_list *));
		if (!vm.objmap.objs)
		{
			ft_putendl_fd(E_ALLOC, 2);
			exit(69);
		}
		ft_memset(vm.objmap.objs, 0, vm.objmap.size * sizeof(t_list *));
		vm.maxobjs = _GC_START;
		vm.objmap.count = 0;
		vm.objcount = 0;
		vm.head = NULL;
		vm.free = NULL;
		vm.ptrap = 0;
		init = 1;
	}
	return (&vm);
}
