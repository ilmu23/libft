/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:47:38 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/28 14:02:21 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_alloc(size_t n)
{
	t_obj	*tmp;
	t_vm	*vm;

	vm = ft_getvm();
	tmp = ft_newobj(vm, n);
	if (!tmp)
		return (NULL);
	ft_push(vm, tmp);
	return (tmp->blk);
}
