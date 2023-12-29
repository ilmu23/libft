/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:39:17 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/29 21:01:04 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_popall(void)
{
	ft_popn(ft_getvm()->stacksize);
}

void	ft_popn(size_t blks)
{
	while (blks)
	{
		ft_pop();
		blks--;
	}
}

void	*ft_pop(void)
{
	t_vm	*vm;

	vm = ft_getvm();
	if (vm->stacksize == 0)
	{
		ft_putendl_fd("vm: ft_pop(): stack underflow", 2);
		ft_exit(E_STACKUF);
	}
	return (vm->stack[--vm->stacksize]);
}
