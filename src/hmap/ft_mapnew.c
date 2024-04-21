/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mapnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 02:18:11 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/21 04:07:40 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lft_gc.h"
#include "lft_hmap_internal.h"

t_hmap	*ft_mapnew(size_t size)
{
	t_hmap	*out;

	out = ft_push(ft_calloc(1, sizeof(*out)));
	if (!out)
		return (NULL);
	out->items = ft_calloc(size, sizeof(t_hmap_pair *));
	ft_popblk(out);
	if (!out->items)
		return (NULL);
	ft_pushn(2, out, out->items);
	out->size = size;
	return (out);
}
