/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_obj.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:47:53 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/28 12:50:48 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_obj	*ft_newobj(t_vm *vm, t_objtype type, size_t n)
{
	t_obj	*obj;

	if (vm->objs == vm->maxobjs)
		ft_clean(vm);
	obj = malloc(sizeof(t_obj));
	if (!obj)
		return (NULL);
	obj->type = type;
	obj->marked = 0;
	obj->next = vm->head;
	obj->blk = malloc(n);
	if (!obj->blk)
		return (NULL);
	vm->head = obj;
	vm->objs++;
	return (obj);
}
