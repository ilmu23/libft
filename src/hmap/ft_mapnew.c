/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 02:18:11 by ivalimak          #+#    #+#             */
/*   Updated: 2024/05/23 20:40:48 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lft_gc.h"
#include "_internal/lft_hmap_internal.h"

t_hmap	*ft_mapnew_size(size_t size)
{
	uint8_t	ptstatus;
	t_hmap	*hmap;

	hmap = ft_push(ft_calloc(1, sizeof(*hmap)));
	if (!hmap)
		return (NULL);
	hmap->bsize = size;
	hmap->size = getnextprime(size);
	hmap->items = ft_calloc(hmap->size, sizeof(t_hmap_pair *));
	ft_popblk(hmap);
	if (!hmap->items)
		return (NULL);
	ptstatus = ft_pushtrap_status();
	ft_pushtrap(PTRAP_DISABLE);
	ft_pushn(2, hmap, hmap->items);
	ft_pushtrap(ptstatus);
	hmap->count = 0;
	return (hmap);
}

t_hmap	*ft_mapnew(void)
{
	return (ft_mapnew_size(HMAP_DEF_SIZE));
}
