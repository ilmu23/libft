/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 03:18:50 by ivalimak          #+#    #+#             */
/*   Updated: 2024/05/27 01:33:05 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lft_gc.h"
#include "lft_mem.h"
#include "lft_str.h"
#include "_internal/lft_hmap_internal.h"

static inline t_hmap_pair	*_newpair(const char *key, const void *val);
static inline uint8_t		_replace(t_hmap *hmap, t_hmap_pair *pair, size_t i);
static inline void		*_dupval(const void *val);

uint8_t	ft_mapadd(t_hmap *hmap, const char *key, const void *val)
{
	t_hmap_pair	*pair;
	t_hmap_pair	*cur;
	size_t		i;
	size_t		j;

	ft_pushn(2, key, val);
	if (!hmap || ((hmap->count * 100) / hmap->size > 70 && !growmap(hmap)))
		return (0);
	pair = _newpair(key, val);
	ft_popblks(2, key, val);
	if (!pair)
		return (0);
	j = 0;
	i = gethash(key, hmap->size, j++);
	cur = hmap->items[i];
	while (cur && cur != (void *)&g_hmap_sentinel)
	{
		if (_replace(hmap, pair, i))
			return (1);
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
	uint8_t		ptstatus;

	if (!key)
		return (NULL);
	pair = ft_push(ft_calloc(1, sizeof(*pair)));
	if (!pair)
		return (NULL);
	pair->key = ft_push(ft_strdup(key));
	if (val)
		pair->value = ft_push(_dupval(val));
	else
		pair->value = NULL;
	ft_popblks(2 + (val != NULL), pair, pair->key, pair->value);
	if (!pair->key || !pair->value)
		return (NULL);
	ptstatus = ft_pushtrap_status();
	ft_pushtrap(PTRAP_DISABLE);
	ft_pushn(2 + (val != NULL), pair, pair->key, pair->value);
	ft_pushtrap(ptstatus);
	return (pair);
}

static inline uint8_t	_replace(t_hmap *hmap, t_hmap_pair *pair, size_t i)
{
	if (ft_strequals(hmap->items[i]->key, pair->key))
	{
		ft_mappop(hmap->items[i]);
		hmap->items[i] = pair;
		return (1);
	}
	return (0);
}

static inline void	*_dupval(const void *val)
{
	size_t		vsize;
	void		*out;

	vsize = ft_getblksize(val);
	out = ft_calloc(1, vsize);
	if (!out)
		return (NULL);
	return (ft_memcpy(out, val, vsize));
}
