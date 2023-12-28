/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:35:52 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/28 14:32:09 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_vm	*ft_newvm(void)
{
	t_vm	*vm;

	vm = malloc(sizeof(t_vm));
	if (!vm)
		return (NULL);
	vm->stacksize = 0;
	vm->maxobjs = GC_START;
	vm->objs = 0;
	vm->head = NULL;
	return (vm);
}

t_vm	*ft_getvm(void)
{
	static t_vm	*vm = NULL;

	if (!vm)
		vm = ft_newvm();
	return (vm);
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
