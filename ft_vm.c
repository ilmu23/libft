/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalimak <ivalimak@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:35:52 by ivalimak          #+#    #+#             */
/*   Updated: 2023/12/29 19:42:47 by ivalimak         ###   ########.fr       */
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
