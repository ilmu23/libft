/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_register.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:12:11 by ivalimak          #+#    #+#             */
/*   Updated: 2024/07/18 13:58:19 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_register.c
 */

#include "lft_put.h"
#include "_internal/lft_gc_internal.h"

static inline void	*_err(const void *blk, const size_t size);

/** @brief Allocates a new t_obj to store a non ft_allocated block
 *
 * Allocates a new t_obj, adding it to the start of the object list
 * storing blk in it and setting it's blksize to size.
 * @param blk Pointer to the block to register
 * @param size Size of the block to register
 * @retval void* Pointer to blk
 */
void	*ft_register(const void *blk, const size_t size)
{
	static t_vm	*vm = NULL;
	t_obj		*obj;

	if (!vm)
		vm = ft_getvm();
	if (vm->objcount == vm->maxobjs)
		ft_clean();
	obj = malloc(sizeof(*obj));
	if (!obj)
		return (_err(blk, size));
	ft_debugmsg(GCALLOC, "Allocated new obj at %p", obj);
	*obj = (t_obj){.marks = 0, .traps = 0, .next = vm->head, .blksize = size,
		.asize = size, .nfree = NULL, .pfree = NULL, .blk = blk};
	vm->head = obj;
	ft_debugmsg(GCALLOC, "Registered new block at &p (%u bytes)", blk, size);
	gc_objmap_add(gc_blkkey(blk), obj);
	vm->objcount++;
	return (ft_push(blk));
}

static inline void	*_err(const void *blk, const size_t size)
{
	ft_putstr_fd("\e[1;31mGC: unable to register block ", 2);
	ft_putxnbr_fd((uintptr_t)blk, 2, 0);
	ft_putstr_fd(" (", 2);
	ft_putunbr_fd(size, 2);
	ft_putstr_fd(" bytes)\e[m\n", 2);
	return ((void *)blk);
}
