/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obj.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:47:53 by ivalimak          #+#    #+#             */
/*   Updated: 2024/06/11 17:15:38 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_obj.c
 */

#include "lft_mem.h"
#include "lft_nbr.h"
#include "lft_put.h"
#include "_internal/lft_gc_internal.h"

/** @brief Creates a new objpair
 *
 * @param *key Key for the object
 * @param *obj Object to store
 * @retval t_objpair* Pointer to the new objpair
 */
t_objpair	*gc_newpair(const char *key, const t_obj *obj)
{
	t_objpair	*out;

	out = gc_calloc(1, sizeof(*out));
	if (!out)
	{
		ft_putendl_fd(E_ALLOC, 2);
		ft_exit(69);
	}
	*out = (t_objpair){.key = key, .obj = obj};
	return (out);
}

/** @brief Allocates and initializes a new t_obj
 *
 * Allocates a new t_obj, adding it to the start of the object list
 * with an obj->blk of n bytes
 * @param n Amount of bytes to allocate for obj->blk
 * @retval t_obj* Pointer to the new object or NULL if
 * the allocation failed
 */
t_obj	*ft_newobj(size_t n)
{
	static t_vm	*vm = NULL;
	t_obj		*obj;

	if (!vm)
		vm = ft_getvm();
	if (vm->objcount == vm->maxobjs)
		ft_clean();
	obj = malloc(sizeof(*obj));
	if (!obj)
		return (NULL);
	ft_debugmsg(GCALLOC, "Allocated new obj at %p", obj);
	*obj = (t_obj){.marks = 0, .traps = 0, .next = vm->head, .blksize = n,};
	obj->blk = malloc(n);
	if (!obj->blk)
		return (NULL);
	vm->head = obj;
	if (vm->free)
		vm->free->pfree = obj;
	obj->nfree = vm->free;
	ft_debugmsg(GCALLOC, "Allocated new block at %p (%u bytes)", obj->blk, n);
	gc_objmap_add(gc_blkkey(obj->blk), obj);
	vm->objcount++;
	return (obj);
}

/** @brief Returns a pointer to the obj containing blk
 *
 * @param *blk Pointer to the block
 * @retval t_obj* Pointer to the object that contains *blk
 */
t_obj	*gc_getobj(const void *blk)
{
	const char	*key;
	t_obj		*out;

	if (!blk)
		return (NULL);
	key = gc_blkkey(blk);
	out = gc_objmap_get(key);
	free((void *)key);
	return (out);
}

/** @brief Returns a string representation of the blocks memory address
 *
 * @param *blk Pointer to the blk
 * @retval char* String representation of the address of blk
 */
char	*gc_blkkey(const void *blk)
{
	size_t		i;
	uintptr_t	addr;
	char		*out;

	addr = (uintptr_t)blk;
	i = ft_uintlen(addr, HEX);
	out = malloc((i + 1) * sizeof(*out));
	if (!out)
	{
		ft_putendl_fd(E_ALLOC, 2);
		ft_exit(69);
	}
	out[i--] = '\0';
	while (addr > 15)
	{
		out[i--] = _HEXARR[addr % 16];
		addr /= 16;
	}
	out[i] = _HEXARR[addr];
	return (out);
}
