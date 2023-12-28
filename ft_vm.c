/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:35:52 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/28 12:34:25 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vm	*ft_newvm(void)
{
	t_vm	*out;

	out = malloc(sizeof(t_vm));
	if (!out)
		return (NULL);
	out->stacksize = 0;
	out->maxobjs = GC_START;
	out->objs = 0;
	out->head = NULL;
	return (out);
}

void	ft_push(t_vm *vm, t_obj *value)
{
	if (vm->stacksize >= STACK_MAX)
	{
		ft_putendl_fd("vm: stack overflow", 2);
		exit(E_STACKOF);
	}
	vm->stack[vm->stacksize++] = value;
}

t_obj	*ft_pop(t_vm *vm)
{
	if (vm->stacksize == 0)
	{
		ft_putendl_fd("vm: stack underflow", 2);
		exit(E_STACKUF);
	}
	return (vm->stack[--vm->stacksize]);
}
