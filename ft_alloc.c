/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:47:38 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/30 15:56:36 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_alloc.c
 */

#include "libft.h"

static t_obj	*ft_findblk(size_t n);

/** @brief Returns an allocated block of at least n bytes
 *
 * Tries to find an unused allocated block of at least n bytes.
 * Allocates a new block if no existing block was found
 * @param n Amount of bytes to allocate
 * @retval void * Pointer to the start of the allocated memory
 * or null if the allocation failed
 */
void	*ft_alloc(size_t n)
{
	t_obj			*tmp;

	tmp = ft_findblk(n);
	if (!tmp)
		tmp = ft_newobj(ft_getvm(), n);
	if (!tmp)
		return (NULL);
	return (tmp->blk);
}

/** @brief Looks for an unused block of memory of at least n bytes
 *
 * @param n Minimum size for the block
 * @retval t_obj * Pointer to the start of the block or null if none found
 */
static t_obj	*ft_findblk(size_t n)
{
	t_vm	*vm;
	t_obj	*obj;

	vm = ft_getvm();
	obj = vm->head;
	ft_markall(vm);
	while (obj)
	{
		if (obj->blksize >= n && !obj->marked)
			break ;
		obj = obj->next;
	}
	ft_unmarkall(vm);
	if (DEBUG_MSG && obj)
		ft_dprintf(DEBUGFD, "Found unused obj at %p (%u bytes)\n",
			obj, obj->blksize);
	return (obj);
}
