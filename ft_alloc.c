/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:47:38 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/28 12:55:29 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_alloc(size_t n, t_objtype type, t_vm *vm)
{
	t_obj	*tmp;

	tmp = ft_newobj(vm, type, n);
	if (!tmp)
		return (NULL);
	ft_push(vm, tmp);
	return (tmp->blk);
}
