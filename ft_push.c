/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:35:34 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/29 20:20:49 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_push(void *blk)
{
	t_vm	*vm;

	vm = ft_getvm();
	if (vm->stacksize >= STACK_MAX)
	{
		ft_putendl_fd("vm: ft_push(): stack overflow", 2);
		ft_exit(E_STACKOF);
	}
	if (blk)
		vm->stack[vm->stacksize++] = blk;
	return (blk);
}

void	**ft_pusharr(void **arr)
{
	size_t	i;

	i = 0;
	ft_push(arr);
	while (arr && arr[i])
		ft_push(arr[i++]);
	return (arr);
}

void	ft_pushn(size_t blks, ...)
{
	va_list	args;

	va_start(args, blks);
	while (blks)
	{
		ft_push(va_arg(args, void *));
		blks--;
	}
	va_end(args);
}
