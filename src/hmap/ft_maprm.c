/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maprm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 04:15:26 by ivalimak          #+#    #+#             */
/*   Updated: 2024/05/23 21:05:05 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lft_str.h"
#include "_internal/lft_hmap_internal.h"

uint8_t	ft_maprm(t_hmap *hmap, const char *key)
{
	t_hmap_pair	*pair;
	size_t		i;
	size_t		j;

	if (!hmap || !key || !hmap->count)
		return (0);
	if ((hmap->count * 100) / hmap->size < 10 && !shrinkmap(hmap))
		return (0);
	j = 0;
	i = gethash(key, hmap->size, j++);
	pair = hmap->items[i];
	while (pair)
	{
		if (pair != (void *)&g_hmap_sentinel && ft_strequals(pair->key, key))
		{
			ft_mappop(pair);
			hmap->items[i] = (void *)&g_hmap_sentinel;
			break ;
		}
		i = gethash(key, hmap->size, j++);
		pair = hmap->items[i];
	}
	hmap->count--;
	return (1);
}
