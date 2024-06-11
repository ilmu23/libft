/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:59:46 by ivalimak          #+#    #+#             */
/*   Updated: 2024/06/07 15:40:20 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_calloc.c
 */

#include "lft_gc.h"
#include "lft_mem.h"

/** @brief Allocates a new block and zero initializes it
 *
 * @param count Amount of objects to allocate
 * @param size Size of the objects to allocate
 * @retval void* Pointer to the newly allocated block
 * or NULL if the allocation failed
 */
void	*ft_calloc(size_t n, size_t size)
{
	void	*out;
	size_t	asize;

	asize = n * size;
	out = ft_alloc(asize);
	if (!out)
		return (NULL);
	ft_memset(out, 0, asize);
	return (out);
}

/** @brief Non garbage collected version of calloc for internal GC use
 *
 * @param count Amount of objects to allocate
 * @param size Size of the objects to allocate
 * @retval void* Pointer to the newly allocated block
 * or NULL if the allocation failed
 */
void	*gc_calloc(size_t n, size_t size)
{
	void	*out;
	size_t	asize;

	asize = n * size;
	out = malloc(asize);
	if (!out)
		return (NULL);
	ft_memset(out, 0, asize);
	return (out);
}
