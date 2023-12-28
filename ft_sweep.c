/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sweep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 11:14:57 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/28 12:50:33 by ivalimak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sweep(t_vm *vm)
{
	t_obj	**obj;
	t_obj	*tmp;

	obj = &vm->head;
	while (*obj)
	{
		if (!(*obj)->marked)
		{
			tmp = *obj;
			*obj = tmp->next;
			vm->objs--;
			free(tmp->blk);
			free(tmp);
		}
		else
		{
			(*obj)->marked = 0;
			obj = &(*obj)->next;
		}
	}
}
