/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obj.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:47:53 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/29 23:49:09 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_obj.c
 */

#include "libft.h"

/** @brief Allocates and initializes a new t_obj
 *
 * Allocates a new t_obj, adding it to the start of the object list
 * with a obj->blk of n bytes
 * @param *vm Pointer to the virtual memory manager
 * @param n Amount of bytes to allocate for obj->blk
 * @retval t_obj * Pointer to the new object or null if
 * the allocation failed
 */
t_obj	*ft_newobj(t_vm *vm, size_t n)
{
	t_obj	*obj;

	if (vm->objs == vm->maxobjs)
		ft_clean(vm);
	obj = malloc(sizeof(t_obj));
	if (!obj)
		return (NULL);
	obj->marked = 0;
	obj->next = vm->head;
	obj->blk = malloc(n);
	if (!obj->blk)
		return (NULL);
	obj->blksize = n;
	vm->head = obj;
	vm->objs++;
	return (obj);
}
