/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:35:52 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/28 22:15:38 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vm	*ft_getvm(void)
{
	static t_vm				vm;
	static unsigned char	init = 0;

	if (!init)
	{
		vm.stacksize = 0;
		vm.maxobjs = GC_START;
		vm.objs = 0;
		vm.head = NULL;
		init = 1;
	}
	return (&vm);
}

void	ft_push(t_vm *vm, void *value)
{
	if (vm->stacksize >= STACK_MAX)
	{
		ft_putendl_fd("vm: stack overflow", 2);
		ft_popall(vm);
		ft_clean(vm);
		exit(E_STACKOF);
	}
	vm->stack[vm->stacksize++] = value;
}

void	ft_popall(t_vm *vm)
{
	while (vm->stacksize)
		ft_pop(vm);
}

t_obj	*ft_pop(t_vm *vm)
{
	if (vm->stacksize == 0)
	{
		ft_putendl_fd("vm: stack underflow", 2);
		ft_clean(vm);
		exit(E_STACKUF);
	}
	return (vm->stack[--vm->stacksize]);
}
