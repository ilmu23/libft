/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:47:38 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/29 22:19:13 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_obj	*ft_findblk(size_t size);

void	*ft_alloc(size_t n)
{
	t_obj			*tmp;

	tmp = ft_findblk(n);
	if (!tmp)
		tmp = ft_newobj(ft_getvm(), n);
	if (!tmp)
		return (NULL);
	return (tmp->blk);
}

static t_obj	*ft_findblk(size_t size)
{
	t_vm	*vm;
	t_obj	*obj;

	vm = ft_getvm();
	obj = vm->head;
	ft_markall(vm);
	while (obj)
	{
		if (obj->blksize >= size && !obj->marked)
			break ;
		obj = obj->next;
	}
	ft_unmarkall(vm);
	return (obj);
}
