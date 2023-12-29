/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mark.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:08:26 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/29 22:17:04 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_mark(t_vm *vm, t_obj *obj);

void	ft_unmarkall(t_vm *vm)
{
	t_obj	*obj;

	obj = vm->head;
	while (obj)
	{
		obj->marked = 0;
		obj = obj->next;
	}
}

void	ft_markall(t_vm *vm)
{
	t_obj	*obj;

	obj = vm->head;
	while (obj)
	{
		ft_mark(vm, obj);
		obj = obj->next;
	}
}

static void	ft_mark(t_vm *vm, t_obj *obj)
{
	size_t	i;

	i = 0;
	while (obj->marked == 0 && i < vm->stacksize)
	{
		if (obj->blk == vm->stack[i++])
			obj->marked = 1;
	}
}
