/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_objpair.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 01:02:13 by ivalimak          #+#    #+#             */
/*   Updated: 2024/06/06 01:06:16 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_objpair.c
 */

#include "lft_put.h"
#include <_internal/lft_gc_internal.h>

/** @brief Returns a new objpair
 *
 * @param *key Key value
 * @param *obj Object value
 * @retval *t_objpair Newly created objpair
 */
t_objpair	*ft_newpair(const char *key, const t_obj *obj)
{
	t_objpair	*out;

	out = malloc(sizeof(*out));
	if (!out)
	{
		ft_putendl_fd(E_ALLOC, 2);
		ft_exit(69);
	}
	out->key = key;
	out->obj = obj;
	return (out);
}
