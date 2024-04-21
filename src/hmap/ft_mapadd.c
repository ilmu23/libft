/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 03:18:50 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/21 04:30:31 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lft_gc.h"
#include "lft_mem.h"
#include "lft_str.h"
#include "lft_hmap_internal.h"

static inline t_hmap_pair	*_newpair(const char *key, const void *val);
static inline void	*_dupval(const void *val);

uint8_t	ft_mapadd(t_hmap *hmap, const char *key, const void *val)
{
	t_hmap_pair	*pair;
	t_hmap_pair	*cur;
	size_t		i;
	size_t		j;

	pair = _newpair(key, val);
	if (!hmap || !pair)
		return (0);
	j = 0;
	i = gethash(key, hmap->size, j++);
	cur = hmap->items[i];
	while (cur && cur != getdelmarker())
	{
		if (ft_strequals(cur->key, key))
		{
			ft_mappop(cur);
			hmap->items[i] = pair;
			return (1);
		}
		i = gethash(key, hmap->size, j++);
		cur = hmap->items[i];
	}
	hmap->items[i] = pair;
	hmap->count++;
	return (1);
}

static inline t_hmap_pair	*_newpair(const char *key, const void *val)
{
	t_hmap_pair	*pair;

	if (!key || !val)
		return (NULL);
	ft_pushn(2, key, val);
	pair = ft_push(ft_calloc(1, sizeof(*pair)));
	ft_popblks(2, key, val);
	if (!pair)
		return (NULL);
	pair->key = ft_push(ft_strdup(key));
	pair->value = ft_push(_dupval(val));
	ft_popblks(3, pair, pair->key, pair->value);
	if (!pair->key || !pair->value)
		return (NULL);
	ft_pushn(3, pair, pair->key, pair->value);
	return (pair);
}

static inline void	*_dupval(const void *val)
{
	size_t		vsize;
	void		*out;

	vsize = ft_getblksize(val);
	out = ft_alloc(vsize);
	if (!out)
		return (NULL);
	return (ft_memcpy(out, val, vsize));
}
