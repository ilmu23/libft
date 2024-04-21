/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 04:01:36 by ivalimak          #+#    #+#             */
/*   Updated: 2024/04/21 04:14:14 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lft_str.h"
#include "lft_hmap_internal.h"

t_hmap_pair	*getdelmarker(void)
{
	static t_hmap_pair	marker = {NULL, NULL};

	return (&marker);
}

size_t	gethash(const char *s, const size_t size, const size_t attempt)
{
	uint64_t	a;
	uint64_t	b;

	a = ft_strhash(s, HMAP_SALT_1, size);
	b = ft_strhash(s, HMAP_SALT_2, size);
	return ((a + (attempt * (b + 1))) % size);
}
