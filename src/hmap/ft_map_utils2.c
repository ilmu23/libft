/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 07:27:08 by ivalimak          #+#    #+#             */
/*   Updated: 2024/05/02 06:20:52 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_internal/lft_hmap_internal.h"

uint8_t	shrinkmap(t_hmap *hmap)
{
	return (resizemap(hmap, hmap->bsize / 2));
}

uint8_t	growmap(t_hmap *hmap)
{
	return (resizemap(hmap, hmap->bsize * 2));
}
