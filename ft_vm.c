/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:35:52 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/29 15:23:35 by ivalimak         ###   ########.fr       */
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

void	ft_push(t_vm *vm, size_t blks, ...)
{
	va_list	args;
	void	*blk;

	va_start(args, blks);
	while (blks)
	{
		if (vm->stacksize >= STACK_MAX)
		{
			ft_putendl_fd("vm: ft_push(): stack overflow", 2);
			ft_exit(E_STACKOF);
		}
		blk = va_arg(args, void *);
		if (blk)
			vm->stack[vm->stacksize++] = blk;
		blks--;
	}
	va_end(args);
}

void	ft_popall(t_vm *vm)
{
	while (vm->stacksize)
		ft_pop(vm);
}

void	ft_popn(t_vm *vm, size_t blks)
{
	while (blks)
	{
		ft_pop(vm);
		blks--;
	}
}

t_obj	*ft_pop(t_vm *vm)
{
	if (vm->stacksize == 0)
	{
		ft_putendl_fd("vm: ft_pop(): stack underflow", 2);
		ft_exit(E_STACKUF);
	}
	return (vm->stack[--vm->stacksize]);
}
