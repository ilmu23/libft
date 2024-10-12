/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maparr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 07:28:13 by ivalimak          #+#    #+#             */
/*   Updated: 2024/10/12 07:40:23 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lft_gc.h"
#include "_internal/lft_hmap_internal.h"

t_hmap_pair	*ft_maparr(const t_hmap *hmap)
{
	size_t		i;
	size_t		j;
	t_hmap_pair	*out;

	if (!hmap)
		return (NULL);
	out = ft_alloc(hmap->count * sizeof(*out));
	if (!out)
		return (NULL);
	for (i = 0, j = 0; i < hmap->size; i++)
		if (hmap->items[i] && hmap->items[i] != (void *)&g_hmap_sentinel)
			out[j++] = *(hmap->items[i]);
	return (out);
}
