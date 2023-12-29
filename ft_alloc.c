/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:47:38 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/29 21:14:20 by ivalimak         ###   ########.fr       */
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
	size_t	i;
	t_vm	*vm;
	t_obj	*obj;

	vm = ft_getvm();
	obj = vm->head;
	while (obj)
	{
		if (obj->blksize >= size)
		{
			i = 0;
			while (i < vm->stacksize)
			{
				if (obj->blk == vm->stack[i++])
					break ;
			}
			if (i == vm->stacksize)
				break ;
		}
		obj = obj->next;
	}
	return (obj);
}
