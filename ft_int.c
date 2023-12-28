/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:53:25 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/28 11:19:02 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pushint(t_vm *vm, int n)
{
	t_obj	*new;

	new = ft_newobj(vm, OBJ_INT);
	if (!new)
		return ;
	new->ival = n;
	ft_push(vm, new);
}

void	ft_pushuint(t_vm *vm, unsigned int n)
{
	t_obj	*new;

	new = ft_newobj(vm, OBJ_UINT);
	if (!new)
		return ;
	new->uival = n;
	ft_push(vm, new);
}
