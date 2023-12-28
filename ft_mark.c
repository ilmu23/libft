/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mark.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:08:26 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/28 11:30:33 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_mark(t_obj *obj);

void	ft_markall(t_vm *vm)
{
	size_t	i;

	i = 0;
	while (i < vm->stacksize)
		ft_mark(vm->stack[i++]);
}

static void	ft_mark(t_obj *obj)
{
	obj->marked = 1;
}
