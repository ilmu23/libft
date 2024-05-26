/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 04:01:36 by ivalimak          #+#    #+#             */
/*   Updated: 2024/05/26 05:07:16 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lft_is.h"
#include "lft_str.h"
#include "_internal/lft_hmap_internal.h"

const uint8_t	g_hmap_sentinel = 42;

static inline void	_swap(t_hmap *hmap, t_hmap *tmp);

uint64_t	getnextprime(uint64_t n)
{
	while (!ft_isprime(n))
		n++;
	return (n);
}

uint8_t	resizemap(t_hmap *hmap, size_t bsize)
{
	t_hmap	*tmp;
	size_t	i;

	if (bsize < HMAP_DEF_SIZE)
		return (1);
	tmp = ft_mapnew_size(bsize);
	if (!tmp)
		return (0);
	i = 0;
	while (i < hmap->size)
	{
		if (hmap->items[i] && hmap->items[i] != (void *)&g_hmap_sentinel)
		{
			if (!ft_mapadd(tmp, hmap->items[i]->key, hmap->items[i]->value))
			{
				ft_mappop_all(tmp);
				return (0);
			}
		}
		i++;
	}
	hmap->bsize = tmp->bsize;
	hmap->count = tmp->count;
	_swap(hmap, tmp);
	return (1);
}

size_t	gethash(const char *s, const size_t size, const size_t attempt)
{
	uint64_t	a;
	uint64_t	b;

	a = ft_strhash(s, HMAP_SALT_1, size);
	b = ft_strhash(s, HMAP_SALT_2, size);
	if (attempt >= 5)
		b *= ft_strhash(s, HMAP_SALT_3, size);
	return ((a + (attempt * (b + 1))) % size);
}

static inline void	_swap(t_hmap *hmap, t_hmap *tmp)
{
	t_hmap_pair	**tmpitems;
	size_t		tmpsize;

	tmpsize = hmap->size;
	hmap->size = tmp->size;
	tmp->size = tmpsize;
	tmpitems = hmap->items;
	hmap->items = tmp->items;
	tmp->items = tmpitems;
	ft_mappop_all(tmp);
}
