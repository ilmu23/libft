/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maprm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 04:15:26 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/21 04:22:48 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lft_str.h"
#include "lft_hmap_internal.h"

void	ft_maprm(t_hmap *hmap, const char *key)
{
	t_hmap_pair	*pair;
	size_t		i;
	size_t		j;

	if (!hmap || !key || !hmap->count)
		return ;
	j = 0;
	i = gethash(key, hmap->size, j++);
	pair = hmap->items[i];
	while (pair)
	{
		if (pair != getdelmarker() && ft_strequals(pair->key, key))
		{
			ft_mappop(pair);
			hmap->items[i] = getdelmarker();
			break ;
		}
		i = gethash(key, hmap->size, j++);
		pair = hmap->items[i];
	}
	hmap->count--;
}
